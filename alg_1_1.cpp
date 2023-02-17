#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

const int MAX_VALUE = 1000000;
const int OBSERVATIONS = 20;
const int PARAM_BEG = 50000;
const int PARAM_STEP = 50000;

void bucketSort(vector<int>& arr) {
    int n = arr.size();

    // Create buckets and distribute elements
    const int num_buckets = 10;
    vector<vector<int>> buckets(num_buckets);
    for (int i = 0; i < n; i++) {
        int bucket_idx = arr[i] / (MAX_VALUE / num_buckets + 1);
        buckets[bucket_idx].push_back(arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < num_buckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Combine buckets back into original array
    int idx = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}
// ------------------------------------------------------------
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Define gap sequence
    int gap = n / 2;
    while (gap > 0) {
        // Perform insertion sort with gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        // Reduce gap
        gap /= 2;
    }
}
// ------------------------------------------------------------
void merge(vector<int>& arr, int left, int middle, int right) {
    vector<int> temp(right - left + 1);

    int i = left;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
// ------------------------------------------------------------
// fillArrayWithRandomNumbers
void fillArrayWithRandomNumbers(vector<int>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, MAX_VALUE);
    for (int i = 0; i < n; i++) {
        arr.push_back(dis(gen));
        // cout << arr[i] << endl;
    }
}

void checkArrayAlg(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void benchmarkBucketSort(vector<int>& arr)
{
    for (int obs = 0, n = PARAM_BEG; obs < OBSERVATIONS; ++obs, n += PARAM_STEP)
    {
        fillArrayWithRandomNumbers(arr, n);
        auto start_time = chrono::high_resolution_clock::now();
        bucketSort(arr);
        auto end_time = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1000000.0;
        cout << "["<< obs+1 <<"]\t" << n << "\t" <<"Time taken: " << time_taken << " seconds" << endl;
        arr.clear();
    }
}

void benchmarkShellSort(vector<int>& arr)
{
    for (int obs = 0, n = PARAM_BEG; obs < OBSERVATIONS; ++obs, n += PARAM_STEP)
    {
        fillArrayWithRandomNumbers(arr, n);
        auto start_time = chrono::high_resolution_clock::now();
        shellSort(arr);
        auto end_time = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1000000.0;
        cout << "["<< obs+1 <<"]\t" << n << "\t" <<"Time taken: " << time_taken << " seconds" << endl;
        arr.clear();
    }
}

void benchmarkMergeSort(vector<int>& arr)
{
    for (int obs = 0, n = PARAM_BEG; obs < OBSERVATIONS; ++obs, n += PARAM_STEP)
    {
        fillArrayWithRandomNumbers(arr, n);
        auto start_time = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end_time = chrono::high_resolution_clock::now();
        double time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1000000.0;
        cout << "["<< obs+1 <<"]\t" << n << "\t" <<"Time taken: " << time_taken << " seconds" << endl;
        arr.clear();
    }
}

int main() {
    vector<int> arr;
    auto start_time = chrono::high_resolution_clock::now();
    cout << "benchmarkBucketSort()" << endl;
    benchmarkBucketSort(arr);
    cout << "benchmarkShellSort()" << endl;
    benchmarkShellSort(arr);
    cout << "benchmarkMergeSort()" << endl;
    benchmarkMergeSort(arr);
    auto end_time = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() / 1000000.0;
    cout << "Done: " << time_taken;
    return 0;
}


