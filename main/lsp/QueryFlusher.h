#ifndef SORBET_QUERY_FLUSHER_H
#define SORBET_QUERY_FLUSHER_H

#include "core/ErrorFlusher.h"

namespace sorbet::realmain::lsp {

class QueryFlusher : public core::ErrorFlusher {
public:
    std::vector<std::unique_ptr<core::lsp::QueryResponse>> queryResponses;
    QueryFlusher() = default;
    ~QueryFlusher() = default;

    void flushErrors(spdlog::logger &logger, const core::GlobalState &gs, core::FileRef file,
                     std::vector<std::unique_ptr<core::ErrorQueueMessage>> errors) override;
};

} // namespace sorbet::realmain::lsp

#endif
