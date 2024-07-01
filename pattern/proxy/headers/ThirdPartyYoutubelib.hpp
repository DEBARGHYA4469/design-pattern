#pragma once 
#include "bits/stdc++.h"
#include "gtest/gtest.h"


/* Interface */
class ThirdPartyYouTubeLib {
public:
    virtual std::vector<std::string> listVideos() = 0;
    virtual std::string getVideoInfo(const std::string& id) = 0;
    virtual void downloadVideo(const std::string& id) = 0;
    virtual ~ThirdPartyYouTubeLib() = default;
};


/* Concrete Implementation of the Youtube Service */
class ThirdPartyYouTubeClass : public ThirdPartyYouTubeLib {
public:
    std::vector<std::string> listVideos() override {
        // Send an API request to YouTube.
        return {"Video1", "Video2", "Video3"}; // Example response
    }

    std::string getVideoInfo(const std::string& id) override {
        // Get metadata about some video.
        std::cout << "Calling Youtube:DB, Need some time" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return "Video info for " + id; // Example response
    }

    void downloadVideo(const std::string& id) override {
        // Download a video file from YouTube.
        std::cout << "Downloading video " << id << std::endl; // Example action
    }
};