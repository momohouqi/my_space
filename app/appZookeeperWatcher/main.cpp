#include <iostream>
//#include "lib/zookeeper/ZookeeperWrapper.h"
#include "../../lib/zookeeper/ZookeeperWrapper.h"

using namespace std;

void init(const string& host) {
    ZookeeperWrapper *zk = new ZookeeperWrapper();

    bool ok = zk->init(host, 2);
    cout << "----zk init status:" << ok << endl;
}

int main(int argc, char* argv[]) {
    cout << "=====app begin" << std::endl;

    string host;
    if (argc > 1) {
        host = argv[1];
    } else {
        host = "localhost:2181";
    }
    init(host);
    cout << "=====app end" << std::endl;
    return 0;
}
