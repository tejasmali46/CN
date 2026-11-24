
#include <iostream>
using namespace std;

int main() {

    int totalFrames, lostFrame;

    cout << "Enter total number of frames: ";
    cin >> totalFrames;

    if (totalFrames <= 0) {
        cout << "Number of frames must be positive.\n";
        return 1;
    }

    cout << "Enter frame number to lose once (0 for no loss): ";
    cin >> lostFrame;

    if (lostFrame < 0 || lostFrame > totalFrames) {
        cout << "Invalid frame number.\n";
        return 1;
    }

    bool lossSimulated = false;

    cout << "\n--- Stop and Wait ARQ ---\n";

    for (int frame = 1; frame <= totalFrames; ++frame) {

        int attempt = 1;
        bool acknowledged = false;

        while (!acknowledged) {

            cout << "Sending Frame " << frame
                 << " (Attempt " << attempt << ")... ";

            if (frame == lostFrame && !lossSimulated) {

                cout << "Frame lost. Timeout occurred.\n";

                lossSimulated = true;
                ++attempt;

            } else {

                cout << "ACK " << frame << " received.\n";

                acknowledged = true;
            }

        }
    }

    cout << "\nAll frames transmitted successfully.\n";

    return 0;
}
