#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, windowSize, lostFrame;

    cout << "Enter number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> windowSize;

    // Input validation
    if (n <= 0 || windowSize <= 0 || windowSize > n) {
        cout << "Invalid number of frames or window size.\n";
        return 1;
    }

    cout << "Enter frame number to simulate loss (-1 for none): ";
    cin >> lostFrame;

    if (lostFrame < -1 || lostFrame >= n) {
        cout << "Invalid frame number.\n";
        return 1;
    }

    vector<bool> received(n, false);

    int base = 0;
    bool lossSimulated = false;

    cout << "\n--- Selective Repeat ARQ ---\n";

    while (base < n) {

        int end = base + windowSize;

        if (end > n)
            end = n;

        cout << "\nSending window: ";

        for (int i = base; i < end; i++)
            cout << i << " ";

        cout << endl;

        // Transmit frames in the current window
        for (int i = base; i < end; i++) {

            cout << "\nSending Frame " << i << endl;

            if (i == lostFrame && !lossSimulated) {

                cout << "Frame " << i << " lost!\n";

                lossSimulated = true;

                continue;
            }

            received[i] = true;

            cout << "Receiver accepts Frame " << i << endl;
            cout << "Individual ACK " << i << " sent.\n";

            // Check whether any previous frame is missing
            bool missingEarlier = false;

            for (int j = base; j < i; j++) {
                if (!received[j]) {
                    missingEarlier = true;
                    break;
                }
            }

            if (missingEarlier) {
                cout << "Frame " << i
                     << " buffered until missing frames arrive.\n";
            }
        }

        // Retransmit only frames that were not received
        for (int i = base; i < end; i++) {

            if (!received[i]) {

                cout << "\nRetransmitting only Frame "
                     << i << endl;

                received[i] = true;

                cout << "Receiver accepts Frame " << i << endl;
                cout << "ACK " << i << " received.\n";
            }
        }

        // Deliver buffered frames in sequence
        cout << "\nDelivering frames in order: ";

        for (int i = base; i < end; i++) {
            cout << i << " ";
        }

        cout << endl;

        base = end;
    }

    cout << "\nAll frames transmitted successfully.\n";

    return 0;
}
