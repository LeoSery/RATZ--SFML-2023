#include <curl/curl.h>
#include <iostream>
#include <string>

class RequestManager
{

public:
	void NewScore(std::string name, int score);
	std::string Scorelist();

private:
	static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
	const std::string BASE_URL = "https://lesratz.fly.dev";
	const std::string SCORE_LIST_ENDPOINT = "/scorelist";
	const std::string NEW_SCORE_ENDPOINT = "/newscore";
	struct curl_slist* slist1;
};
