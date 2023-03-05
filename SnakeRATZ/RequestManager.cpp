#include "RequestManager.h"

size_t RequestManager::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string RequestManager::Scorelist() {
	// Initialize libcurl
	CURL* curl = curl_easy_init();

	if (curl) {
		// Fetch the player score list
		std::string score_list_url = BASE_URL + SCORE_LIST_ENDPOINT;
		std::string score_list_response;
		curl_easy_setopt(curl, CURLOPT_URL, score_list_url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &score_list_response);
		CURLcode res = curl_easy_perform(curl);

		if (res == CURLE_OK) {
			std::cout << "Player score list response: " << score_list_response << std::endl;
		}
		else {
			std::cerr << "Failed to fetch player score list: " << curl_easy_strerror(res) << std::endl;
		}
		// Clean up libcurl resources
		curl_easy_cleanup(curl);
		return score_list_response;
	}
	return "no curl";
}

void RequestManager::NewScore(std::string name, int score) {
	// Initialize libcurl
	CURL* curl = curl_easy_init();

	if (curl) {
		// Update or insert a player's score

		slist1 = curl_slist_append(slist1, "Content-Type: application/json");

		std::string new_score_url = BASE_URL + NEW_SCORE_ENDPOINT;
		std::string new_score_response;
		std::string request = "{\"pseudo\": \"" + name + "\", \"score\" : \"" + std::to_string(score) + "\"}";
		curl_easy_setopt(curl, CURLOPT_URL, new_score_url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &new_score_response);
		CURLcode res = curl_easy_perform(curl);

		if (res == CURLE_OK) {
			std::cout << "New score response: " << new_score_response << std::endl;
		}
		else {
			std::cerr << "Failed to update or insert player's score: " << curl_easy_strerror(res) << std::endl;
		}

		// Clean up libcurl resources
		curl_easy_cleanup(curl);
	}
}
