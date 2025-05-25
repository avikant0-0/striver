class Solution {
public:
    void merge(int left, int mid, int right, vector<int>& a, vector<int>& temp) {
        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (a[i] <= a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++];
        }

        while (i <= mid) temp[k++] = a[i++];
        while (j <= right) temp[k++] = a[j++];

        for (int x = left; x <= right; ++x) a[x] = temp[x];
    }

    void mergeSort(int i, int j, vector<int>& a, vector<int>& temp) {
        if (i >= j) return;

        int mid = i + (j - i) / 2;
        mergeSort(i, mid, a, temp);
        mergeSort(mid + 1, j, a, temp);
        merge(i, mid, j, a, temp);
    }

    vector<int> sortArray(vector<int>& a) {
        vector<int> temp(a.size());
        mergeSort(0, a.size() - 1, a, temp);
        return a;
    }
};
