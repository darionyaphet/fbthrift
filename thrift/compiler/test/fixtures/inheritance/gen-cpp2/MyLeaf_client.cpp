/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "src/gen-cpp2/MyLeafAsyncClient.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> MyLeaf_do_leaf_pargs;
typedef apache::thrift::ThriftPresult<true> MyLeaf_do_leaf_presult;

const char* MyLeafAsyncClient::getServiceName() {
  return "MyLeaf";
}

template <typename Protocol_>
void MyLeafAsyncClient::do_leafT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "MyLeaf.do_leaf", connectionContext_.get());
  MyLeaf_do_leaf_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "do_leaf", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper MyLeafAsyncClient::recv_wrapped_do_leafT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  prot->setInput(state.buf());
  auto guard = folly::makeGuard([&] {prot->setInput(nullptr);});
  apache::thrift::ContextStack* ctx = state.ctx();
  std::string _fname;
  int32_t protoSeqId = 0;
  apache::thrift::MessageType mtype;
  ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<std::exception, apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    prot->readMessageBegin(_fname, mtype, protoSeqId);
    if (mtype == apache::thrift::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(prot);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::T_REPLY) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (_fname.compare("do_leaf") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    MyLeaf_do_leaf_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void MyLeafAsyncClient::recv_do_leafT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_do_leafT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}



void MyLeafAsyncClient::do_leaf(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  do_leafImpl(false, rpcOptions, std::move(callback));
}

void MyLeafAsyncClient::do_leaf(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  do_leafImpl(false, rpcOptions, std::move(callback));
}

void MyLeafAsyncClient::do_leafImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      do_leafT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      do_leafT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void MyLeafAsyncClient::sync_do_leaf() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_do_leaf(rpcOptions);
}

void MyLeafAsyncClient::sync_do_leaf(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  do_leafImpl(true, rpcOptions, std::move(callback));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_do_leaf(_returnState);
}

folly::Future<folly::Unit> MyLeafAsyncClient::future_do_leaf() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_do_leaf(rpcOptions);
}

folly::Future<folly::Unit> MyLeafAsyncClient::future_do_leaf(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_do_leaf, channel_);
  do_leaf(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> MyLeafAsyncClient::header_future_do_leaf(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_do_leaf, channel_);
  do_leaf(rpcOptions, std::move(callback));
  return _future;
}

void MyLeafAsyncClient::do_leaf(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  do_leaf(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper MyLeafAsyncClient::recv_wrapped_do_leaf(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }
  switch(state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return recv_wrapped_do_leafT(&reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_do_leafT(&reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void MyLeafAsyncClient::recv_do_leaf(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_do_leaf(state);
  if (ew) {
    ew.throw_exception();
  }
}

void MyLeafAsyncClient::recv_instance_do_leaf(::apache::thrift::ClientReceiveState& state) {
  recv_do_leaf(state);
}

folly::exception_wrapper MyLeafAsyncClient::recv_instance_wrapped_do_leaf(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_do_leaf(state);
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
