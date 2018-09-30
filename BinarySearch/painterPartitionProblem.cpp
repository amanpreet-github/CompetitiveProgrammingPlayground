#include<bits/stdc++.h>

using namespace std;

long long MOD = 10000003;
long long maxTime = INT_MAX;

bool
isPossible(long long int mid, long long int numberOfPainters, vector<long long> &board, long long timeTakenByPainter) {

    vector<long long> maxTimeTaken(numberOfPainters, 0);

    long long int iter = 0, boardIter = 0, singleBoardTime, timeTaken = 0;

    while (iter < numberOfPainters) {
        while (timeTaken < mid) {

            if (boardIter == board.size()) {
                sort(maxTimeTaken.begin(), maxTimeTaken.end());
                maxTime = min(maxTime % MOD, maxTimeTaken[numberOfPainters - 1] % MOD);
                return true;
            }
            singleBoardTime = ((1 % MOD) * (board[boardIter] % MOD)) % MOD;

            maxTimeTaken[iter] = ((maxTimeTaken[iter] % MOD) + (singleBoardTime % MOD)) % MOD;
            timeTaken = maxTimeTaken[iter];
            boardIter++;

        }
        maxTimeTaken[iter] = ((maxTimeTaken[iter] % MOD) - (singleBoardTime) % MOD) % MOD;
        iter++;
        boardIter--;
        timeTaken = 0;
    }
    return false;
}

void binarySearch(vector<long long> &board, long long start, long long end, long long numberOfPainters,
                  long long int timeTakenByPainter) {
    while (start <= end) {
        long long int mid = (start % MOD) + ((end % MOD - start % MOD) % MOD) / 2;
        if (isPossible(mid, numberOfPainters, board, timeTakenByPainter)) {
            end = ((mid % MOD) - (1 % MOD)) % MOD;
        } else start = ((mid % MOD) + (1 % MOD)) % MOD;
    }
    cout << ((maxTime % MOD) * (timeTakenByPainter) % MOD) % MOD;
}

int main() {
    long long int numOfPainters, timeTakenByPainter, noOfBoards, boardLength, maximumTiming, singleBoardTime;

    cin >> numOfPainters >> timeTakenByPainter >> noOfBoards;
    vector<long long> board(noOfBoards);

    maximumTiming = 0;
    for (int i = 0; i < noOfBoards; i++) {
        cin >> boardLength;
        board[i] = boardLength;
        singleBoardTime = ((boardLength % MOD) * (1 % MOD)) % MOD;
        maximumTiming = ((maximumTiming % MOD) + (singleBoardTime % MOD)) % MOD;
    }
    binarySearch(board, 0, maximumTiming, numOfPainters, timeTakenByPainter);

}
// trick take initially time taken by Painter equal to 1.