class SnapshotArray {
    map<pair<int, int>, int> mymap_;
    int snapshot_id_;
    map<int, vector<int>> index_to_snaps_;
public:
    SnapshotArray(int length) {
        snapshot_id_ = 0;
    }
    
    void set(int index, int val) {
        mymap_[{snapshot_id_, index}] = val;
        index_to_snaps_[index].push_back(snapshot_id_);
    }
    
    int snap() {
        snapshot_id_++;
        return snapshot_id_-1;
    }
    
    int get(int index, int snap_id) {
        auto up = std::upper_bound (index_to_snaps_[index].begin(), index_to_snaps_[index].end(), snap_id);
        if (up == index_to_snaps_[index].begin()) return 0;
        --up;
        int target_snap_id =*up;
        return mymap_[{target_snap_id, index}];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
