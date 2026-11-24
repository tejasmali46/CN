
#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    int totalFrames, windowSize, lostFrame;

    cout << "Enter total number of frames: ";
    cin >> totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    if (totalFrames <= 0 || windowSize <= 0 || windowSize > totalFrames) {
        cout << "Invalid frame count or window size.\n";
        return 1;
    }

    cout << "Enter frame number to lose once (0 for no loss): ";
    cin >> lostFrame;

    if (lostFrame < 0 || lostFrame > totalFrames) {
        cout << "Invalid frame number.\n";
        return 1;
    }

    int base = 1;
    bool lossSimulated = false;

    cout << "\n--- Go Back N ARQ ---\n";

    while (base <= totalFrames) {

        int windowEnd = min(base + windowSize - 1, totalFrames);
        bool lossInWindow = false;
        int firstLostFrame = 0;

        cout << "\nSending window " << base << " to " << windowEnd << ":\n";

        for (int frame = base; frame <= windowEnd; ++frame) {

            cout << "Sending Frame " << frame << "... ";

            if (frame == lostFrame && !lossSimulated) {

                cout << "Frame lost.\n";

                lossSimulated = true;
                lossInWindow = true;
                firstLostFrame = frame;

            } else if (lossInWindow) {

                cout << "Receiver discards Frame " << frame
                     << " (out of order).\n";

            } else {

                cout << "Cumulative ACK up to Frame " << frame
                     << " received.\n";

            }
        }

        if (lossInWindow) {

            cout << "Timeout occurred. Go-Back-N retransmits from Frame "
                 << firstLostFrame << ":\n";

            for (int frame = firstLostFrame; frame <= windowEnd; ++frame) {

                cout << "Retransmitting Frame " << frame
                     << "... ACK received.\n";

            }
        }

        base = windowEnd + 1;
    }

    cout << "\nAll frames transmitted successfully.\n";

    return 0;
}
