class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int , int>lost_map;
        unordered_set<int>players;
       
       for(int i=0; i<matches.size(); i++){
        int loser = matches[i][1];
        int winner = matches[i][0];

        players.insert(winner);
        players.insert(loser);

        lost_map[loser]++;
       }
       vector<int>notlost;
       vector<int>lostonce;

  for (int player : players) {

            if (lost_map.find(player) == lost_map.end()) {
                notlost.push_back(player);
            }
            else if (lost_map[player] == 1) {
                lostonce.push_back(player);
            }
        }
            
   sort(notlost.begin(), notlost.end());
    sort(lostonce.begin(), lostonce.end());


    return {notlost , lostonce};
    }
};