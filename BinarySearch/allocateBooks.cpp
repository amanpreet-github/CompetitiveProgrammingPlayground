#include<bits/stdc++.h>

using namespace std;

bool isPossible(int mid, int numberOfStudents, vector<int> &books, int &maxPages) {

    vector<int> maxPagesTaken(numberOfStudents, 0);

    int iter = 0, bookIter = 0, pagesTaken = 0;

    while (iter < numberOfStudents) {
        while (pagesTaken <= mid) {

            if (bookIter == books.size()) {
                sort(maxPagesTaken.begin(), maxPagesTaken.end());

                maxPages = min(maxPages, maxPagesTaken[numberOfStudents - 1]);
                return true;
            }

            maxPagesTaken[iter] = ((maxPagesTaken[iter]) + (books[bookIter]));
            pagesTaken = maxPagesTaken[iter];
            bookIter++;

        }
        maxPagesTaken[iter] = ((maxPagesTaken[iter]) - (books[bookIter - 1]));
        iter++;
        bookIter--;
        pagesTaken = 0;
    }
    return false;
}

int binarySearch(vector<int> &books, int start, int end, int numberOfStudents, int &maxPages) {
    while (start <= end) {
        int mid = (start) + ((end - start)) / 2;
        if (isPossible(mid, numberOfStudents, books, maxPages)) {
            end = ((mid) - (1));
        } else start = ((mid) + (1));
    }
    return ((maxPages));
}

int main() {
    int numberOfStudents, noOfBooks, bookPages, maximumPages = 0;

    cin >> noOfBooks;
    vector<int> books(noOfBooks);
    cin >> numberOfStudents;

    for (int i = 0; i < noOfBooks; i++) {
        cin >> bookPages;
        books[i] = bookPages;
        maximumPages = ((maximumPages) + (books[i]));
    }
    int maxPages = INT_MAX;
    cout << binarySearch(books, 0, maximumPages, numberOfStudents, maxPages);

}

