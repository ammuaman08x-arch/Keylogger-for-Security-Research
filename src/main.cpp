#include "application.h"
#include "utils.h"

#include <iostream>
#include <exception>

int main() {
    try {
        SecurityResearch::Application app;
        
        if (!app.Initialize()) {
            SecurityResearch::Utils::PrintWarning("Failed to initialize Security Research application.");
            return 1;
        }

        app.Run();
        app.Shutdown();
    }
    catch (const std::exception& ex) {
        std::cerr << "[CRITICAL ERROR] Unhandled Exception: " << ex.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "[CRITICAL ERROR] Unknown exception occurred." << std::endl;
        return 1;
    }

    return 0;
}
