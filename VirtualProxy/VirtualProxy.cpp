#include <iostream>
#include <string>

// Subject interface
class Image {
public:
    virtual void display() = 0;
};

// RealSubject class
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& name) : filename(name) {
        loadFromDisk();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }

    void loadFromDisk() {
        std::cout << "Loading image from disk: " << filename << std::endl;
    }
};

// Proxy class (Virtual Proxy)
class ProxyImage : public Image {
private:
    RealImage* realImage;
    std::string filename;

public:
    ProxyImage(const std::string& name) : filename(name), realImage(nullptr) {}

    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage(filename);
        }
        realImage->display();
    }
};

int main() {
    // Using the ProxyImage to display images
    Image* image1 = new ProxyImage("image1.jpg");
    Image* image2 = new ProxyImage("image2.jpg");

    // Image loading and display will only happen when display() is called
    image1->display();
    image2->display();

    // Clean up
    delete image1;
    delete image2;

    return 0;
}
