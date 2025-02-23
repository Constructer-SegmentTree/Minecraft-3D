#include "GUI/BaseWindow.hpp"
#include "DefaultChecker.hpp"
#include "CreateChecker.hpp"
#include "TickChecker.hpp"
using namespace std;

/*
 * @brief Window for seek.
 * @todo Do other message worker.
*/
class Window: public BaseWindow<Window> 
{
public:
    /*
     * @brief Init the window.
    */
    Window() {
        *this += make_pair(CreateChecker(),CreateChecker::CreateWorker);
        *this += make_pair(TickChecker(),TickChecker::TickWorker);
        *this += make_pair(DefaultChecker(),DefaultChecker::DefaultWorker);
    }
};

int main() {
    Window MinecraftRunner;
    MinecraftRunner.Create(L"Hello");

    MSG msg = {};
    while(GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    } return 0;
}
