#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

int M, N, A[200000], B[200000], k = 1;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;


int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
        B[i]--;
    }
    sort(B, B + N);
    int p = 0;
    for (int i = 0; i < M; i++)
    {
        // insert(A[i]);
        maxHeap.push(A[i]);

        while (maxHeap.size() > k)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while (minHeap.size() > 0 && maxHeap.size() < k)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();    
        }

        while (p < N && B[p] <= i)
        {
            // get
            cout << maxHeap.top() << endl;
            k++;
            
            while (minHeap.size() > 0 && maxHeap.size() < k)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();    
            }

            p++;
            // cout << maxHeap.size() << " " << minHeap.size() << endl;
        }
    }
    // system("pause");
}