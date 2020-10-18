//
// Created by Yannie Lee on 2020-10-09.
//




class Solution {

private:

    vector<string> result;

    //map的列表初始化
    map<int,int> MapSearch = {
            {0,1},{1,2},{2,4},{3,8},{4,1},
            {5,2},{6,4},{7,8},{8,16},{9,32}
    };

    void findBinary(int num, int index, pair<int, int>& time){

        if(time.first > 11 || time.second > 59 ) return; //剪枝 在这里剪枝，时间打败100%了

        if( num == 0 ){ //找到了一个解
            if( time.first > 11 || time.second > 59)
                return;
            string temp_hour = to_string(time.first);
            string temp_minute = to_string(time.second);

            if( temp_minute.size() == 1 )
                temp_minute.insert(0, "0");
//            if( temp_hour.empty() )       //这里不用加上这一句 因为time.first为空的时候 to_string就已经转化成0了
//                temp_hour.insert(0, "0");

            result.push_back(temp_hour + ":" + temp_minute);
            return ;
        }

        for( int i = index; i < MapSearch.size(); i ++ ){

            pair<int,int> store = time;

            if( i < 4 )
                time.first += MapSearch[i];
            else
                time.second += MapSearch[i];

            findBinary( num-1, i+1, time ); //这里是i，不是index呀！！
            time = store;
        }

    }


public:
    vector<string> readBinaryWatch(int num) {

        result.clear();

        pair<int, int> time(0, 0);

        findBinary(num, 0, time);

        return result;

    }
};


//第一次写的代码。。。 写不下去了

class Solution {

private:

    vector<string> result;

    //map的列表初始化
    map<int,int> MapSearch = {
            {1,1},{2,2},{3,4},{4,8},{5,1},
            {6,2},{7,4},{8,8},{9,16},{10,32}
    };

    void findBinary(int num, int index, int times, vector<int>& q){

        if( times == num ){
            result.emplace_back(q);
            return ;
        }

        for( int i = index; i < MapSearch.size(); i ++ ){

            if( i <= 4 ){
                int temp = q.back() + MapSearch[i];

                if( temp <= 11 ){
                    q.pop_back(); q.push_back(temp);
                }else
                    q.push_back(MapSearch[i]);

            }else if( i > 4 && q.empty() ){
                q.push_back(0); q.push_back( MapSearch[i] );
            }else
                q.push_back( MapSearch[i] );

            findBinary(num, index+1, times+1, q);
            q.pop_back();
        }

    }

    void change(  ){

    }

public:
    vector<string> readBinaryWatch(int num) {

        result.clear();

        vector<int> q;

        findBinary(num, 1, 0, q);

        return result;

    }
};
