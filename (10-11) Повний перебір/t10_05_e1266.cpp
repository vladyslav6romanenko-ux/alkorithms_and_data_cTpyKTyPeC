#include <iostream>
#include <vector>

using namespace std;

int best_sum = 0;
vector<int> best_subset;


bool bnb(int N, const vector<int>& tracks, int idx, int current_sum, int remaining_sum, vector<int>& current_subset) {
    if (current_sum > best_sum) {
        best_sum = current_sum;
        best_subset = current_subset;
    }
    

    if (best_sum == N) return true;
    

    if (idx == tracks.size() || current_sum + remaining_sum <= best_sum) {
        return false;
    }
    
    if (current_sum + tracks[idx] <= N) {
        current_subset.push_back(tracks[idx]);
        if (bnb(N, tracks, idx + 1, current_sum + tracks[idx], remaining_sum - tracks[idx], current_subset)) {
            return true;
        }
        current_subset.pop_back(); 
    }
    

    if (bnb(N, tracks, idx + 1, current_sum, remaining_sum - tracks[idx], current_subset)) {
        return true;
    }
    
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    while (cin >> N >> M) {
        vector<int> tracks(M);
        int total_sum = 0;
        for (int i = 0; i < M; ++i) {
            cin >> tracks[i];
            total_sum += tracks[i];
        }
        
        best_sum = 0;
        best_subset.clear();
        vector<int> current_subset;
        current_subset.reserve(M); 
        
        bnb(N, tracks, 0, 0, total_sum, current_subset);
        

        cout << "sum:" << best_sum << "\n";
    }
    
    return 0;
}
