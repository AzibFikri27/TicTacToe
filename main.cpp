/*
 * Graphical Tic-Tac-Toe Game using WinBGIm Library
 * 
 * SETUP INSTRUCTIONS:
 * -------------------
 * To compile this project, you need to have the WinBGIm library installed.
 * 
 * For Code::Blocks:
 * 1. Download WinBGIm from: https://winbgim.codecutter.org/
 * 2. Copy graphics.h and winbgim.h to your compiler's include directory
 * 3. Copy libbgi.a to your compiler's lib directory
 * 4. In Project -> Build Options -> Linker Settings, add these libraries:
 *    - libbgi.a
 *    - gdi32
 *    - user32
 *    - comdlg32
 *    - winmm
 *    - ole32
 *    - oleaut32
 * 
 * For Visual Studio:
 * 1. Download and install WinBGIm library
 * 2. Add the include and lib directories to your project settings
 * 3. In Project Properties -> Linker -> Input -> Additional Dependencies, add:
 *    - libbgi.a
 *    - gdi32.lib
 *    - user32.lib
 *    - comdlg32.lib
 *    - winmm.lib
 *    - ole32.lib
 *    - oleaut32.lib
 * 
 * GAME FEATURES:
 * -------------
 * - Single Player mode (vs AI with strategic logic)
 * - Multiplayer mode (two human players)
 * - Graphical interface with mouse controls
 * - Win/Draw detection
 * - Play again option
 * 
 * OOP CONCEPTS DEMONSTRATED:
 * -------------------------
 * - Encapsulation: Private data members with public getters/setters
 * - Inheritance: Shape -> Cross/Circle, Player -> HumanPlayer/ComputerPlayer
 * - Polymorphism: Virtual functions (draw(), getMove())
 * - Composition: Cell owns Shape objects
 * - Aggregation: Game aggregates Board and Players
 * - Array of Objects: Board uses array of Cells
 */

#include "Game.h"
#include <graphics.h>
#include <iostream>

int main() {
    // Create and initialize the game
    Game game(800, 600);
    
    try {
        game.initialize();
        game.run();
        game.cleanup();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    closegraph();
    return 0;
}
