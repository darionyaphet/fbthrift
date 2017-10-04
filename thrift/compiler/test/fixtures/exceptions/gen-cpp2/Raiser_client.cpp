/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "src/gen-cpp2/RaiserAsyncClient.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> Raiser_doBland_pargs;
typedef apache::thrift::ThriftPresult<true> Raiser_doBland_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_doRaise_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>> Raiser_doRaise_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get200_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, std::string*>> Raiser_get200_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get500_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, std::string*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>> Raiser_get500_presult;

const char* RaiserAsyncClient::getServiceName() {
  return "Raiser";
}

template <typename Protocol_>
void RaiserAsyncClient::doBlandT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "Raiser.doBland", connectionContext_.get());
  Raiser_doBland_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "doBland", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doBlandT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
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
    if (_fname.compare("doBland") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    Raiser_doBland_presult result;
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
void RaiserAsyncClient::recv_doBlandT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doBlandT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

template <typename Protocol_>
void RaiserAsyncClient::doRaiseT(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "Raiser.doRaise", connectionContext_.get());
  Raiser_doRaise_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "doRaise", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doRaiseT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
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
    if (_fname.compare("doRaise") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    Raiser_doRaise_presult result;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
    if (result.getIsSet(0)) {
      interior_ew = folly::make_exception_wrapper< ::cpp2::Banal>(result.get<0>().ref());
      return; // from try_and_catch
    }
    if (result.getIsSet(1)) {
      interior_ew = folly::make_exception_wrapper< ::cpp2::Fiery>(result.get<1>().ref());
      return; // from try_and_catch
    }
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void RaiserAsyncClient::recv_doRaiseT(Protocol_* prot, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doRaiseT(prot, state);
  if (ew) {
    ew.throw_exception();
  }
}

template <typename Protocol_>
void RaiserAsyncClient::get200T(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "Raiser.get200", connectionContext_.get());
  Raiser_get200_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "get200", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get200T(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
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
    if (_fname.compare("get200") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    Raiser_get200_presult result;
    result.get<0>().value = &_return;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
    if (result.getIsSet(0)) {
      // _return pointer has been filled
      return; // from try_and_catch
    }
    else {
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::MISSING_RESULT, "failed: unknown result");
      return; // from try_and_catch
    }
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void RaiserAsyncClient::recv_get200T(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get200T(prot, _return, state);
  if (ew) {
    ew.throw_exception();
  }
}

template <typename Protocol_>
void RaiserAsyncClient::get500T(Protocol_* prot, bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto header = std::make_shared<apache::thrift::transport::THeader>(apache::thrift::transport::THeader::ALLOW_BIG_FRAMES);
  header->setProtocolId(getChannel()->getProtocolId());
  header->setHeaders(rpcOptions.releaseWriteHeaders());
  connectionContext_->setRequestHeader(header.get());
  std::unique_ptr<apache::thrift::ContextStack> ctx = this->getContextStack(this->getServiceName(), "Raiser.get500", connectionContext_.get());
  Raiser_get500_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<Protocol_>(prot, rpcOptions, std::move(callback), std::move(ctx), header, channel_.get(), "get500", writer, sizer, false, useSync);
  connectionContext_->setRequestHeader(nullptr);
}

template <typename Protocol_>
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get500T(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
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
    if (_fname.compare("get500") != 0) {
      prot->skip(apache::thrift::protocol::T_STRUCT);
      prot->readMessageEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    ::apache::thrift::SerializedMessage smsg;
    smsg.protocolType = prot->protocolType();
    smsg.buffer = state.buf();
    ctx->onReadData(smsg);
    Raiser_get500_presult result;
    result.get<0>().value = &_return;
    result.read(prot);
    prot->readMessageEnd();
    ctx->postRead(state.header(), state.buf()->length());
    if (result.getIsSet(0)) {
      // _return pointer has been filled
      return; // from try_and_catch
    }
    if (result.getIsSet(1)) {
      interior_ew = folly::make_exception_wrapper< ::cpp2::Fiery>(result.get<1>().ref());
      return; // from try_and_catch
    }
    if (result.getIsSet(2)) {
      interior_ew = folly::make_exception_wrapper< ::cpp2::Banal>(result.get<2>().ref());
      return; // from try_and_catch
    }
    else {
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::TApplicationExceptionType::MISSING_RESULT, "failed: unknown result");
      return; // from try_and_catch
    }
  }
  );
  auto ew = interior_ew ? std::move(interior_ew) : std::move(caught_ew);
  if (ew) {
    ctx->handlerErrorWrapped(ew);
  }
  return ew;
}

template <typename Protocol_>
void RaiserAsyncClient::recv_get500T(Protocol_* prot, std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get500T(prot, _return, state);
  if (ew) {
    ew.throw_exception();
  }
}



void RaiserAsyncClient::doBland(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  doBlandImpl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doBland(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  doBlandImpl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doBlandImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      doBlandT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      doBlandT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_doBland() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_doBland(rpcOptions);
}

void RaiserAsyncClient::sync_doBland(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  doBlandImpl(true, rpcOptions, std::move(callback));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_doBland(_returnState);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doBland() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_doBland(rpcOptions);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doBland(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doBland, channel_);
  doBland(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_doBland(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doBland, channel_);
  doBland(rpcOptions, std::move(callback));
  return _future;
}

void RaiserAsyncClient::doBland(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  doBland(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doBland(::apache::thrift::ClientReceiveState& state) {
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
      return recv_wrapped_doBlandT(&reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_doBlandT(&reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_doBland(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doBland(state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_doBland(::apache::thrift::ClientReceiveState& state) {
  recv_doBland(state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_doBland(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_doBland(state);
}

void RaiserAsyncClient::doRaise(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  doRaiseImpl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doRaise(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  doRaiseImpl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doRaiseImpl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      doRaiseT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      doRaiseT(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_doRaise() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_doRaise(rpcOptions);
}

void RaiserAsyncClient::sync_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  doRaiseImpl(true, rpcOptions, std::move(callback));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_doRaise(_returnState);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doRaise() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_doRaise(rpcOptions);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doRaise, channel_);
  doRaise(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doRaise, channel_);
  doRaise(rpcOptions, std::move(callback));
  return _future;
}

void RaiserAsyncClient::doRaise(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  doRaise(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doRaise(::apache::thrift::ClientReceiveState& state) {
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
      return recv_wrapped_doRaiseT(&reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_doRaiseT(&reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_doRaise(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doRaise(state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_doRaise(::apache::thrift::ClientReceiveState& state) {
  recv_doRaise(state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_doRaise(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_doRaise(state);
}

void RaiserAsyncClient::get200(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  get200Impl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get200(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  get200Impl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get200Impl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      get200T(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      get200T(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_get200(std::string& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_get200(rpcOptions, _return);
}

void RaiserAsyncClient::sync_get200(apache::thrift::RpcOptions& rpcOptions, std::string& _return) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  get200Impl(true, rpcOptions, std::move(callback));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_get200(_return, _returnState);
}

folly::Future<std::string> RaiserAsyncClient::future_get200() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_get200(rpcOptions);
}

folly::Future<std::string> RaiserAsyncClient::future_get200(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::string> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<std::string>>(std::move(_promise), recv_wrapped_get200, channel_);
  get200(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_get200(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<std::string, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<std::string>>(std::move(_promise), recv_wrapped_get200, channel_);
  get200(rpcOptions, std::move(callback));
  return _future;
}

void RaiserAsyncClient::get200(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  get200(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get200(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
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
      return recv_wrapped_get200T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_get200T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_get200(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get200(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_get200(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_get200(_return, state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_get200(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_get200(_return, state);
}

void RaiserAsyncClient::get500(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  get500Impl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get500(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  get500Impl(false, rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get500Impl(bool useSync, apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  switch(getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      get500T(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      get500T(&writer, useSync, rpcOptions, std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_get500(std::string& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_get500(rpcOptions, _return);
}

void RaiserAsyncClient::sync_get500(apache::thrift::RpcOptions& rpcOptions, std::string& _return) {
  apache::thrift::ClientReceiveState _returnState;
  auto callback = std::make_unique<apache::thrift::ClientSyncCallback>(&_returnState, false);
  get500Impl(true, rpcOptions, std::move(callback));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(_returnState.exception());
    _returnState.exception().throw_exception();
  }
  recv_get500(_return, _returnState);
}

folly::Future<std::string> RaiserAsyncClient::future_get500() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_get500(rpcOptions);
}

folly::Future<std::string> RaiserAsyncClient::future_get500(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::string> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<std::string>>(std::move(_promise), recv_wrapped_get500, channel_);
  get500(rpcOptions, std::move(callback));
  return _future;
}

folly::Future<std::pair<std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_get500(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<std::string, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<std::string>>(std::move(_promise), recv_wrapped_get500, channel_);
  get500(rpcOptions, std::move(callback));
  return _future;
}

void RaiserAsyncClient::get500(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  get500(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get500(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
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
      return recv_wrapped_get500T(&reader, _return, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return recv_wrapped_get500T(&reader, _return, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_get500(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get500(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_get500(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_get500(_return, state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_get500(std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_get500(_return, state);
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
