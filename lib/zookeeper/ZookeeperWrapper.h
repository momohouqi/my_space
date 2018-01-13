#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H
#include "zookeeper/zookeeper.h"
#include <string>

class ZookeeperWrapper
{
public:
    enum Status {

    };

    ZookeeperWrapper();
    ~ZookeeperWrapper();
    /**
     * @brief init
     * @param host,ip:port
     * @param recv_timeout
     * @return success or not
     */
    bool init(const std::string& host, int recv_timeout);
    /**
     * @brief createNodeSynchronously
     * @param path
     * @param value
     * @param nodeType ZOO_EPHEMERAL, ZOO_SEQUENCE,...
     * @param returnNodePath, if nodeType is ZOO_SEQUENCE, it will be different from gived path
     * @return
     */
    int createNodeSynchronously(const std::string& path, const std::string& value, int nodeType,
                                std::string& returnNodePath);
    int getNodeSynchronously(const std::string& path, std::string& value, const watcher_fn &watcher);
private:
    bool _isInitOK() const;
private:
    zhandle_t *m_zkHandle;
};

#endif // ZOOKEEPER_H
