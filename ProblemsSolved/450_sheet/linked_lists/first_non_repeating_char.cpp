using itr =  list<char>::iterator;
string FirstNonRepeating(string A){

    unordered_map<char,itr> char_cnt;
    list<char> no_rep;

    for(auto &x: A){
        auto pr = char_cnt.find(x);

        //if we're seeing this character first time
        if(pr == char_cnt.end()){
            no_rep.push_back(x);
            char_cnt[x] = --(no_rep.end());
        }
        else{
            auto it = char_cnt[x];
            if(it != no_rep.end())
                no_rep.erase(it);
            //set it to .end() for case when char occurs more than two times
            char_cnt[x] = no_rep.end();
        }
        if(!no_rep.size())
            x = '#';
        else
            x = no_rep.front();
    }
    return A;
}
