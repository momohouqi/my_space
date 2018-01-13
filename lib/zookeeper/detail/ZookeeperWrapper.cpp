#include "../ZookeeperWrapper.h"

ZookeeperWrapper::ZookeeperWrapper():
    m_zkHandle(NULL)
{
}

ZookeeperWrapper::~ZookeeperWrapper()
{
    if (_isInitOK()) zookeeper_close(m_zkHandle);
}

bool ZookeeperWrapper::init(const std::string &host, int recv_timeout)
{
    watcher_fn watcher_fun = NULL;
    m_zkHandle = zookeeper_init(host.c_str(), watcher_fun, recv_timeout, 0, 0, 0);
    if (!m_zkHandle) return false;
}

int ZookeeperWrapper::createNodeSynchronously(const std::string &path, const std::string &value, int nodeType, std::string &returnNodePath)
{
    if (!_isInitOK()) return ZINVALIDSTATE;

    /*
    ACL_vector acl;
    acl.count = 1;
    acl.data = new ACL;
    */
    ACL_vector acl = ZOO_CREATOR_ALL_ACL;
    char returnPath[1024] = {0};
    int status = zoo_create(m_zkHandle, path.c_str(), value.c_str(), value.length(), &acl,
                            nodeType, returnPath, sizeof(returnPath));
    returnNodePath = returnPath;
    return status;
}

int ZookeeperWrapper::getNodeSynchronously(const std::string &path, std::string &value, const watcher_fn &watcher)
{
    if (!_isInitOK()) return ZINVALIDSTATE;

    char* buff = NULL;
    int buffLen = 0;
    void *nothingToPassToWatcher = NULL;
    int status = zoo_wget(m_zkHandle, path.c_str(), watcher, nothingToPassToWatcher, buff, &buffLen, NULL);
    value = buff;
    return status;
}

bool ZookeeperWrapper::_isInitOK() const
{
    return m_zkHandle != NULL;
}
