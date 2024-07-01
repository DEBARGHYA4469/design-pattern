#include "ThirdPartyYoutubelib.hpp"

class CachedYoutubeProxy : public ThirdPartyYouTubeLib {
private:
    ThirdPartyYouTubeLib* service;
    std::vector<std::string> listCache;
    std::unordered_map<std::string, std::string> videoCache;
    bool needReset = false;
public:
	CachedYoutubeProxy(ThirdPartyYouTubeLib* service) : service(service) {}
	std::vector<std::string> listVideos() override {
        if (listCache.empty() || needReset) {
            listCache = service->listVideos();
        }
        return listCache;
    }
    std::string getVideoInfo(const std::string& id) override {
        if (videoCache.find(id) == videoCache.end() || needReset) {
            videoCache[id] = service->getVideoInfo(id);
        }
        return videoCache[id];
    }
    void downloadVideo(const std::string& id) override {
        // Example check to avoid downloading the same video multiple times
        if (needReset || videoCache.find(id) == videoCache.end()) {
            service->downloadVideo(id);
        }
    }
};