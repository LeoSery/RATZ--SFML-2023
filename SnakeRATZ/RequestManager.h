#include <iostream>
#include <string>
#include <curl/curl.h>

class RequestManager
{

private:
	const std::string BASE_URL = "https://lesratz.fly.dev";
	const std::string SCORE_LIST_ENDPOINT = "/scorelist";
	const std::string NEW_SCORE_ENDPOINT = "/newscore";
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
	struct curl_slist* slist1;

public:

	std::string Scorelist();
	void NewScore(std::string name, int score);
};

