/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "src/gen-cpp2/PubSubStreamingService.h"

#include <folly/io/IOBuf.h>
#include <folly/io/IOBufQueue.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <thrift/lib/cpp/transport/THeader.h>
#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>
#include <thrift/lib/cpp2/server/Cpp2ConnContext.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> PubSubStreamingService_client_pargs;
typedef apache::thrift::ThriftPresult<true> PubSubStreamingService_client_presult;
typedef apache::thrift::ThriftPresult<false> PubSubStreamingService_server_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>> PubSubStreamingService_server_presult;
typedef apache::thrift::ThriftPresult<false> PubSubStreamingService_both_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::FooEx>> PubSubStreamingService_both_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>, apache::thrift::FieldData<2, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_returnstream_pargs;
typedef apache::thrift::ThriftPresult<true> PubSubStreamingService_returnstream_presult;
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, apache::thrift::protocol::T_I32, int32_t*>> PubSubStreamingService_takesstream_pargs;
typedef apache::thrift::ThriftPresult<true> PubSubStreamingService_takesstream_presult;
typedef apache::thrift::ThriftPresult<false> PubSubStreamingService_clientthrows_pargs;
typedef apache::thrift::ThriftPresult<true> PubSubStreamingService_clientthrows_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_client(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_client<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_client(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_client_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.client", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function client";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("client", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function client";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_client<ProtocolIn_,ProtocolOut_>, throw_wrapped_client<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  using stream_elem_type = int32_t;
  // TODO: this can likely be moved into an external, not generated helper
  yarpl::Reference<yarpl::flowable::Flowable<folly::IOBufQueue>> inbound_stream; 
  // TODO: hook up inbound stream somehow
  // inbound_stream = ctx->getConnectionContext()->getStreamContext()->incomingStream(); // or something
  assert(false && "not implemented yet");
  yarpl::Reference<yarpl::flowable::Flowable<stream_elem_type>> typed_flowable;
  /*
    = inbound_stream->map([](folly::IOBufQueue buf) {
        stream_elem_type stream_elem;
        // TODO: do this in a worker thread?
        ProtocolIn_ prot;
        prot.setInput(&buf);
        apache::thrift::Cpp2Ops<stream_elem_type>::read(&prot, &stream_elem);
        return stream_elem;
    });
  */
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_client(std::move(callback), typed_flowable);
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_client(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  PubSubStreamingService_client_presult result;
  return serializeResponse("client", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_client(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function client";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("client", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function client";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_server(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_server<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_server(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_server_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.server", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function server";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("server", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function server";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_server<ProtocolIn_,ProtocolOut_>, throw_wrapped_server<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  using stream_elem_type = int32_t;
  // TODO: this can likely be moved into an external, not generated helper
  yarpl::Reference<yarpl::flowable::Flowable<folly::IOBufQueue>> inbound_stream; 
  // TODO: hook up inbound stream somehow
  // inbound_stream = ctx->getConnectionContext()->getStreamContext()->incomingStream(); // or something
  assert(false && "not implemented yet");
  yarpl::Reference<yarpl::flowable::Flowable<stream_elem_type>> typed_flowable;
  /*
    = inbound_stream->map([](folly::IOBufQueue buf) {
        stream_elem_type stream_elem;
        // TODO: do this in a worker thread?
        ProtocolIn_ prot;
        prot.setInput(&buf);
        apache::thrift::Cpp2Ops<stream_elem_type>::read(&prot, &stream_elem);
        return stream_elem;
    });
  */
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_server(std::move(callback), typed_flowable);
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_server(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  PubSubStreamingService_server_presult result;
  return serializeResponse("server", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_server(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
  PubSubStreamingService_server_presult result;
  if (ew.with_exception([&]( ::cpp2::FooEx& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<0>().ref() = e;
    result.setIsSet(0, true);
  }
  )) {} else
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function server";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("server", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function server";
    }
  }
  auto queue = serializeResponse("server", &prot, protoSeqId, ctx, result);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendReply(queue.move());
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_both(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_both<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_both(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_both_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.both", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function both";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("both", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function both";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_both<ProtocolIn_,ProtocolOut_>, throw_wrapped_both<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  using stream_elem_type = int32_t;
  // TODO: this can likely be moved into an external, not generated helper
  yarpl::Reference<yarpl::flowable::Flowable<folly::IOBufQueue>> inbound_stream; 
  // TODO: hook up inbound stream somehow
  // inbound_stream = ctx->getConnectionContext()->getStreamContext()->incomingStream(); // or something
  assert(false && "not implemented yet");
  yarpl::Reference<yarpl::flowable::Flowable<stream_elem_type>> typed_flowable;
  /*
    = inbound_stream->map([](folly::IOBufQueue buf) {
        stream_elem_type stream_elem;
        // TODO: do this in a worker thread?
        ProtocolIn_ prot;
        prot.setInput(&buf);
        apache::thrift::Cpp2Ops<stream_elem_type>::read(&prot, &stream_elem);
        return stream_elem;
    });
  */
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_both(std::move(callback), typed_flowable);
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_both(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  PubSubStreamingService_both_presult result;
  return serializeResponse("both", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_both(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
  PubSubStreamingService_both_presult result;
  if (ew.with_exception([&]( ::cpp2::FooEx& e) {
    ctx->userExceptionWrapped(true, ew);
    result.get<0>().ref() = e;
    result.setIsSet(0, true);
  }
  )) {} else
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function both";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("both", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function both";
    }
  }
  auto queue = serializeResponse("both", &prot, protoSeqId, ctx, result);
  queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
  return req->sendReply(queue.move());
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_returnstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_returnstream<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_returnstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_returnstream_pargs args;
  int32_t uarg_i32_from{0};
  args.get<0>().value = &uarg_i32_from;
  int32_t uarg_i32_to{0};
  args.get<1>().value = &uarg_i32_to;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.returnstream", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function returnstream";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("returnstream", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function returnstream";
    }
  }
  auto callback = std::make_unique<apache::thrift::PubsubHandlerCallback<int32_t>>(std::move(req), std::move(c), ctx->getProtoSeqId(), eb, tm, ctx);
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_returnstream(std::move(callback), args.get<0>().ref(), args.get<1>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_returnstream(int32_t protoSeqId, apache::thrift::ContextStack* ctx, yarpl::Reference<yarpl::flowable::Flowable<int32_t>> const& _return) {
  ProtocolOut_ prot;
  PubSubStreamingService_returnstream_presult result;
  (void) _return; // TODO: this gets serialized in PubsubHandlerCallback
  result.setIsSet(0, true);
  return serializeResponse("returnstream", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_returnstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function returnstream";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("returnstream", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function returnstream";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_takesstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_takesstream<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_takesstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_takesstream_pargs args;
  int32_t uarg_other_param{0};
  args.get<0>().value = &uarg_other_param;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.takesstream", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function takesstream";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("takesstream", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function takesstream";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_takesstream<ProtocolIn_,ProtocolOut_>, throw_wrapped_takesstream<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  using stream_elem_type = int32_t;
  // TODO: this can likely be moved into an external, not generated helper
  yarpl::Reference<yarpl::flowable::Flowable<folly::IOBufQueue>> inbound_stream; 
  // TODO: hook up inbound stream somehow
  // inbound_stream = ctx->getConnectionContext()->getStreamContext()->incomingStream(); // or something
  assert(false && "not implemented yet");
  yarpl::Reference<yarpl::flowable::Flowable<stream_elem_type>> typed_flowable;
  /*
    = inbound_stream->map([](folly::IOBufQueue buf) {
        stream_elem_type stream_elem;
        // TODO: do this in a worker thread?
        ProtocolIn_ prot;
        prot.setInput(&buf);
        apache::thrift::Cpp2Ops<stream_elem_type>::read(&prot, &stream_elem);
        return stream_elem;
    });
  */
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_takesstream(std::move(callback), typed_flowable, args.get<0>().ref());
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_takesstream(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  PubSubStreamingService_takesstream_presult result;
  return serializeResponse("takesstream", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_takesstream(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function takesstream";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("takesstream", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function takesstream";
    }
  }
}

template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::_processInThread_clientthrows(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  auto pri = iface_->getRequestPriority(ctx, apache::thrift::concurrency::NORMAL);
  processInThread<ProtocolIn_, ProtocolOut_>(std::move(req), std::move(buf),std::move(iprot), ctx, eb, tm, pri, false, &PubSubStreamingServiceAsyncProcessor::process_clientthrows<ProtocolIn_, ProtocolOut_>, this);
}
template <typename ProtocolIn_, typename ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::process_clientthrows(std::unique_ptr<apache::thrift::ResponseChannel::Request> req, std::unique_ptr<folly::IOBuf> buf, std::unique_ptr<ProtocolIn_> iprot,apache::thrift::Cpp2RequestContext* ctx,folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  // make sure getConnectionContext is null
  // so async calls don't accidentally use it
  iface_->setConnectionContext(nullptr);
  PubSubStreamingService_clientthrows_pargs args;
  std::unique_ptr<apache::thrift::ContextStack> c(this->getContextStack(this->getServiceName(), "PubSubStreamingService.clientthrows", ctx));
  try {
    deserializeRequest(args, buf.get(), iprot.get(), c.get());
  }
  catch (const std::exception& ex) {
    ProtocolOut_ prot;
    if (req) {
      LOG(ERROR) << ex.what() << " in function clientthrows";
      apache::thrift::TApplicationException x(apache::thrift::TApplicationException::TApplicationExceptionType::PROTOCOL_ERROR, ex.what());
      folly::IOBufQueue queue = serializeException("clientthrows", &prot, ctx->getProtoSeqId(), nullptr, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), ctx->getHeader()->getWriteTransforms(), ctx->getHeader()->getMinCompressBytes()));
      eb->runInEventBaseThread([queue = std::move(queue), req = std::move(req)]() mutable {
        req->sendReply(queue.move());
      }
      );
      return;
    }
    else {
      LOG(ERROR) << ex.what() << " in oneway function clientthrows";
    }
  }
  auto callback = std::make_unique<apache::thrift::HandlerCallback<void>>(std::move(req), std::move(c), return_clientthrows<ProtocolIn_,ProtocolOut_>, throw_wrapped_clientthrows<ProtocolIn_, ProtocolOut_>, ctx->getProtoSeqId(), eb, tm, ctx);
  using stream_elem_type = int32_t;
  // TODO: this can likely be moved into an external, not generated helper
  yarpl::Reference<yarpl::flowable::Flowable<folly::IOBufQueue>> inbound_stream; 
  // TODO: hook up inbound stream somehow
  // inbound_stream = ctx->getConnectionContext()->getStreamContext()->incomingStream(); // or something
  assert(false && "not implemented yet");
  yarpl::Reference<yarpl::flowable::Flowable<stream_elem_type>> typed_flowable;
  /*
    = inbound_stream->map([](folly::IOBufQueue buf) {
        stream_elem_type stream_elem;
        // TODO: do this in a worker thread?
        ProtocolIn_ prot;
        prot.setInput(&buf);
        apache::thrift::Cpp2Ops<stream_elem_type>::read(&prot, &stream_elem);
        return stream_elem;
    });
  */
  if (!callback->isRequestActive()) {
    callback.release()->deleteInThread();
    return;
  }
  ctx->setStartedProcessing();
  iface_->async_tm_clientthrows(std::move(callback), typed_flowable);
}

template <class ProtocolIn_, class ProtocolOut_>
folly::IOBufQueue PubSubStreamingServiceAsyncProcessor::return_clientthrows(int32_t protoSeqId, apache::thrift::ContextStack* ctx) {
  ProtocolOut_ prot;
  PubSubStreamingService_clientthrows_presult result;
  return serializeResponse("clientthrows", &prot, protoSeqId, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void PubSubStreamingServiceAsyncProcessor::throw_wrapped_clientthrows(std::unique_ptr<apache::thrift::ResponseChannel::Request> req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  ProtocolOut_ prot;
   {
    if (req) {
      LOG(ERROR) << ew.what().toStdString() << " in function clientthrows";
      apache::thrift::TApplicationException x(ew.what().toStdString());
      ctx->userExceptionWrapped(false, ew);
      ctx->handlerErrorWrapped(ew);
      folly::IOBufQueue queue = serializeException("clientthrows", &prot, protoSeqId, ctx, x);
      queue.append(apache::thrift::transport::THeader::transform(queue.move(), reqCtx->getHeader()->getWriteTransforms(), reqCtx->getHeader()->getMinCompressBytes()));
      req->sendReply(queue.move());
      return;
    }
    else {
      LOG(ERROR) << ew.what().toStdString() << " in oneway function clientthrows";
    }
  }
}

} // cpp2
namespace apache { namespace thrift {

}} // apache::thrift
