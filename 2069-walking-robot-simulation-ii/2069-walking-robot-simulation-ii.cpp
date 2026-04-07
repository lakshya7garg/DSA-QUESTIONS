class Robot {
private:
    vector<vector<int>> pos;
    vector<string> dir;
    int idx=0;
    int n;
    bool moved=false;
public:
    Robot(int width, int height){
        for(int x=0; x<width; x++){
            pos.push_back({x,0});
            dir.push_back("East");
        }

        for(int y=1; y<height; y++){
            pos.push_back({width-1,y});
            dir.push_back("North");
        }

        for(int x=width-2; x>=0; x--){
            pos.push_back({x,height-1});
            dir.push_back("West");
        }

        for(int y=height-2; y>=1; y--) {
            pos.push_back({0,y});
            dir.push_back("South");
        }

        n=pos.size();
    }

    void step(int num){
        if(num>0) moved=true;
        idx=(idx+num)%n;
    }

    vector<int> getPos(){
        return pos[idx];
    }

    string getDir() {
        if(idx==0) {
            return moved?"South":"East";
    }
    return dir[idx];
}
};
/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */