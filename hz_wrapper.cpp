
#include "hz_wrapper.h"

#include <hazelcast/client/hazelcast_client.h>
#include <hazelcast/client/client_config.h>
#include <hazelcast/logger.h>

int hazelcast_map_get(const char *map_name, const char *key) {
    using namespace hazelcast::client;

    client_config conf;
    conf.get_logger_config().level(hazelcast::logger::level::off);

    auto cli = hazelcast::new_client(std::move(conf)).get();

    auto map = cli.get_map(map_name).get();

    return map->get<std::string, int>(key).get().get_value_or(-1);
}