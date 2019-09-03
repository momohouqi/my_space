#include <iostream>
#include <cstdio>
#include <cstring>
//#include "lib/zookeeper/ZookeeperWrapper.h"
#include "../../lib/zookeeper/ZookeeperWrapper.h"

using namespace std;
void watcher(zhandle_t *zh, int type, int state, const char* path, void* watcherCtx) {
    cout << "===from watcher" << endl;
}

void init(const string& host) {
    ZookeeperWrapper *zk = new ZookeeperWrapper();

    bool ok = zk->init(host, 2);
    cout << "----zk init status:" << ok << endl;

    string value;
    ok = zk->getNodeSynchronously("/", value, watcher);
    cout << "---getNodeValue:" << value << endl;
}

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
<<<<<<< HEAD
=======
    cout << "Using server port:" << host << endl;
>>>>>>> 1668b9caaf5c652e54a39d79f5f7bc72b1199390
    init(host);
    cout << "=====app end" << std::endl;
    return 0;
}
