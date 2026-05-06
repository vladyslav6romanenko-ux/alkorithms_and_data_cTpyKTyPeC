#include <iostream>
#include <vector>

using namespace std;

int best_sum = 0;
vector<int> best_subset;

void find_tracks(int N, const vector<int>& tracks, int index, int current_sum, vector<int>& current_subset) {
    if (current_sum > best_sum) {
        best_sum = current_sum;
        best_subset = current_subset;
    }
    
    for (int i = index; i < tracks.size(); ++i) {
        if (current_sum + tracks[i] <= N) {
            current_subset.push_back(tracks[i]);
            find_tracks(N, tracks, i + 1, current_sum + tracks[i], current_subset);
            current_subset.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    while (cin >> N) {
        int M;
        cin >> M;
        vector<int> tracks(M);
        for (int i = 0; i < M; ++i) {
            cin >> tracks[i];
        }
        
        best_sum = 0;
        best_subset.clear();
        vector<int> current_subset;
        
        find_tracks(N, tracks, 0, 0, current_subset);
        
        for (int t : best_subset) {
            cout << t << " ";
        }
        cout << "sum:" << best_sum << "\n";
    }
    
    return 0;
}
