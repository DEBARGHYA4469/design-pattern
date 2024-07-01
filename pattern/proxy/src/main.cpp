#include "ThirdPartyYoutubelib.hpp" 
#include "CachedYoutubeProxy.hpp"

class YoutubeManager {
protected:
	ThirdPartyYouTubeLib* service; 
public:
	YoutubeManager(ThirdPartyYouTubeLib* service) : service (service) {} 
	void renderVideoPage (const std::string& id){
		std::string info = service->getVideoInfo (id);
		std::cout << "Rendering video page: \n" << info << std::endl;
	}
	void renderListPanel() {
        std::vector<std::string> list = service->listVideos();
        // Render the list of video thumbnails.
        std::cout << "Rendering list of videos: \n";
        for (const auto& video : list) {
            std::cout << video << " ";
        }
        std::cout << std::endl;
    }
    void reactOnUserInput() {
        renderVideoPage("Video1");
        renderListPanel();
    } 
}; 

TEST (YoutubeManagerTest, WithoutProxy) {
	ThirdPartyYouTubeClass* service = new ThirdPartyYouTubeClass();
	YoutubeManager* manager = new YoutubeManager(service);
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	std::cout << std::endl;
}

TEST (YoutubeManagerTest, WithProxy) {
	ThirdPartyYouTubeClass* service = new ThirdPartyYouTubeClass();
	/* Intercept with a Cache Proxy */
	CachedYoutubeProxy *cacheProxy = new CachedYoutubeProxy(service);
	YoutubeManager* manager = new YoutubeManager(cacheProxy);
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	manager->renderVideoPage("c4340c3d-86d4-4fca-a584-9f4fdaf1a902");
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}