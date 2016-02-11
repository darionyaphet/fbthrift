/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>
#include <thrift/lib/cpp/TApplicationException.h>
#include <folly/io/IOBuf.h>
#include <folly/io/Cursor.h>
#include <boost/operators.hpp>




namespace cpp2 {

class MyUnion;
class MyField;
class MyStruct;
class StructWithUnion;
class RecursiveStruct;

class MyUnion : private boost::totally_ordered<MyUnion> {
 public:
  enum Type {
    __EMPTY__ = 0,
    anInteger = 1,
    aString = 2,
  } ;

  MyUnion() :
      type_(Type::__EMPTY__) {}

  MyUnion(MyUnion&& rhs) :
      type_(Type::__EMPTY__) {
    if (this == &rhs) {return; }
    if (rhs.type_ == Type::__EMPTY__) { return; }
    switch(rhs.type_) {
      case Type::anInteger:
      {
        set_anInteger(std::move(rhs.value_.anInteger));
        break;
      }
      case Type::aString:
      {
        set_aString(std::move(rhs.value_.aString));
        break;
      }
      default:
      {
        assert(false);
        break;
      }
    }
    rhs.__clear();
  }

  MyUnion(const MyUnion& rhs) :
      type_(Type::__EMPTY__) {
    if (this == &rhs) {return; }
    if (rhs.type_ == Type::__EMPTY__) { return; }
    switch(rhs.type_) {
      case Type::anInteger:
      {
        set_anInteger(rhs.value_.anInteger);
        break;
      }
      case Type::aString:
      {
        set_aString(rhs.value_.aString);
        break;
      }
      default:
      {
        assert(false);
        break;
      }
    }
  }

  MyUnion& operator=(MyUnion&& rhs) {
    if (this == &rhs) {return *this; }
    __clear();
    if (rhs.type_ == Type::__EMPTY__) { return *this; }
    switch(rhs.type_) {
      case Type::anInteger:
      {
        set_anInteger(std::move(rhs.value_.anInteger));
        break;
      }
      case Type::aString:
      {
        set_aString(std::move(rhs.value_.aString));
        break;
      }
      default:
      {
        assert(false);
        break;
      }
    }
    rhs.__clear();
    return *this;
  }

  MyUnion& operator=(const MyUnion& rhs) {
    if (this == &rhs) {return *this; }
    __clear();
    if (rhs.type_ == Type::__EMPTY__) { return *this; }
    switch(rhs.type_) {
      case Type::anInteger:
      {
        set_anInteger(rhs.value_.anInteger);
        break;
      }
      case Type::aString:
      {
        set_aString(rhs.value_.aString);
        break;
      }
      default:
      {
        assert(false);
        break;
      }
    }
    return *this;
  }
  void __clear();

  virtual ~MyUnion() throw() {
    __clear();
  }

  union storage_type {
    int32_t anInteger;
    std::string aString;

    storage_type() {}
    ~storage_type() {}
  } ;
  bool operator==(const MyUnion& rhs) const;

  bool operator < (const MyUnion& rhs) const {
    if (type_ != rhs.type_) { return type_ < rhs.type_; }
    switch(type_) {
      case Type::anInteger:
      {
        return value_.anInteger < rhs.value_.anInteger;
        break;
      }
      case Type::aString:
      {
        return value_.aString < rhs.value_.aString;
        break;
      }
      default:
      {
        return false;
        break;
      }
    }
  }

  int32_t& set_anInteger(int32_t t = int32_t()) {
    __clear();
    type_ = Type::anInteger;
    ::new (std::addressof(value_.anInteger)) int32_t(t);
    return value_.anInteger;
  }

  std::string& set_aString(std::string const &t) {
    __clear();
    type_ = Type::aString;
    ::new (std::addressof(value_.aString)) std::string(t);
    return value_.aString;
  }

  std::string& set_aString(std::string&& t) {
    __clear();
    type_ = Type::aString;
    ::new (std::addressof(value_.aString)) std::string(std::move(t));
    return value_.aString;
  }

  template<typename... T, typename = ::apache::thrift::safe_overload_t<std::string, T...>> std::string& set_aString(T&&... t) {
    __clear();
    type_ = Type::aString;
    ::new (std::addressof(value_.aString)) std::string(std::forward<T>(t)...);
    return value_.aString;
  }

  int32_t const & get_anInteger() const {
    assert(type_ == Type::anInteger);
    return value_.anInteger;
  }

  std::string const & get_aString() const {
    assert(type_ == Type::aString);
    return value_.aString;
  }

  int32_t & mutable_anInteger() {
    assert(type_ == Type::anInteger);
    return value_.anInteger;
  }

  std::string & mutable_aString() {
    assert(type_ == Type::aString);
    return value_.aString;
  }

  int32_t move_anInteger() {
    assert(type_ == Type::anInteger);
    return std::move(value_.anInteger);
  }

  std::string move_aString() {
    assert(type_ == Type::aString);
    return std::move(value_.aString);
  }

  Type getType() const { return type_; }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
 protected:
  template <class T>
  void destruct(T &val) {
    (&val)->~T();
  }

  Type type_;
  storage_type value_;
};

void swap(MyUnion& a, MyUnion& b);

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::MyUnion>::clear( ::cpp2::MyUnion* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::MyUnion>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyUnion>::write(Protocol* proto, const  ::cpp2::MyUnion* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyUnion>::read(Protocol* proto,   ::cpp2::MyUnion* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyUnion>::serializedSize(Protocol* proto, const  ::cpp2::MyUnion* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyUnion>::serializedSizeZC(Protocol* proto, const  ::cpp2::MyUnion* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

class MyField : private boost::totally_ordered<MyField> {
 public:

  MyField() :
      opt_value(0),
      value(0),
      req_value(0) {}
  // FragileConstructor for use in initialization lists only

  MyField(apache::thrift::FragileConstructor, int64_t opt_value__arg, int64_t value__arg, int64_t req_value__arg) :
      opt_value(std::move(opt_value__arg)),
      value(std::move(value__arg)),
      req_value(std::move(req_value__arg)) {}

  MyField(MyField&&) = default;

  MyField(const MyField&) = default;

  MyField& operator=(MyField&&) = default;

  MyField& operator=(const MyField&) = default;
  void __clear();

  virtual ~MyField() throw() {}

  int64_t opt_value;
  int64_t value;
  int64_t req_value;

  struct __isset {
    __isset() {
      __clear();
    }

    void __clear() {
      opt_value = false;
      value = false;
    }

    bool opt_value;
    bool value;
  } __isset;
  bool operator==(const MyField& rhs) const;
  bool operator < (const MyField& rhs) const;

  const int64_t* get_opt_value() const& {
    return __isset.opt_value ? std::addressof(opt_value) : nullptr;
  }

  int64_t* get_opt_value() & {
    return __isset.opt_value ? std::addressof(opt_value) : nullptr;
  }
  int64_t* get_opt_value() && = delete;

  void set_opt_value(int64_t opt_value_) {
    opt_value = opt_value_;
    __isset.opt_value = true;
  }

  int64_t get_value() const {
    return value;
  }

  void set_value(int64_t value_) {
    value = value_;
    __isset.value = true;
  }

  int64_t get_req_value() const {
    return req_value;
  }

  void set_req_value(int64_t req_value_) {
    req_value = req_value_;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
};

void swap(MyField& a, MyField& b);

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::MyField>::clear( ::cpp2::MyField* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::MyField>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyField>::write(Protocol* proto, const  ::cpp2::MyField* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyField>::read(Protocol* proto,   ::cpp2::MyField* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyField>::serializedSize(Protocol* proto, const  ::cpp2::MyField* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyField>::serializedSizeZC(Protocol* proto, const  ::cpp2::MyField* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

class MyStruct : private boost::totally_ordered<MyStruct> {
 public:

  MyStruct() {}
  // FragileConstructor for use in initialization lists only

  MyStruct(apache::thrift::FragileConstructor, std::unique_ptr< ::cpp2::MyField> opt_ref__arg, std::unique_ptr< ::cpp2::MyField> ref__arg, std::unique_ptr< ::cpp2::MyField> req_ref__arg) :
      opt_ref(std::move(opt_ref__arg)),
      ref(std::move(ref__arg)),
      req_ref(std::move(req_ref__arg)) {}

  MyStruct(MyStruct&&) = default;
  MyStruct(const MyStruct& src0);

  MyStruct& operator=(MyStruct&&) = default;
  MyStruct& operator=(const MyStruct& src1);
  void __clear();

  virtual ~MyStruct() throw() {}

  std::unique_ptr< ::cpp2::MyField> opt_ref;
  std::unique_ptr< ::cpp2::MyField> ref;
  std::unique_ptr< ::cpp2::MyField> req_ref;

  struct __isset {
    __isset() {
      __clear();
    }

    void __clear() {}

  } __isset;
  bool operator==(const MyStruct& rhs) const;
  bool operator < (const MyStruct& rhs) const;

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
};

void swap(MyStruct& a, MyStruct& b);

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::MyStruct>::clear( ::cpp2::MyStruct* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::MyStruct>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyStruct>::write(Protocol* proto, const  ::cpp2::MyStruct* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyStruct>::read(Protocol* proto,   ::cpp2::MyStruct* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyStruct>::serializedSize(Protocol* proto, const  ::cpp2::MyStruct* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::MyStruct>::serializedSizeZC(Protocol* proto, const  ::cpp2::MyStruct* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

class StructWithUnion : private boost::totally_ordered<StructWithUnion> {
 public:

  StructWithUnion() :
      aDouble(0) {}
  // FragileConstructor for use in initialization lists only

  StructWithUnion(apache::thrift::FragileConstructor, std::unique_ptr< ::cpp2::MyUnion> u__arg, double aDouble__arg,  ::cpp2::MyField f__arg) :
      u(std::move(u__arg)),
      aDouble(std::move(aDouble__arg)),
      f(std::move(f__arg)) {}

  StructWithUnion(StructWithUnion&&) = default;
  StructWithUnion(const StructWithUnion& src3);

  StructWithUnion& operator=(StructWithUnion&&) = default;
  StructWithUnion& operator=(const StructWithUnion& src4);
  void __clear();

  virtual ~StructWithUnion() throw() {}

  std::unique_ptr< ::cpp2::MyUnion> u;
  double aDouble;
   ::cpp2::MyField f;

  struct __isset {
    __isset() {
      __clear();
    }

    void __clear() {
      aDouble = false;
      f = false;
    }

    bool aDouble;
    bool f;
  } __isset;
  bool operator==(const StructWithUnion& rhs) const;
  bool operator < (const StructWithUnion& rhs) const;

  double get_aDouble() const {
    return aDouble;
  }

  void set_aDouble(double aDouble_) {
    aDouble = aDouble_;
    __isset.aDouble = true;
  }
  const  ::cpp2::MyField& get_f() const&;
   ::cpp2::MyField get_f() &&;
  template <typename T>
  void set_f(T&& f_);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
};

void swap(StructWithUnion& a, StructWithUnion& b);

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::StructWithUnion>::clear( ::cpp2::StructWithUnion* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::StructWithUnion>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::StructWithUnion>::write(Protocol* proto, const  ::cpp2::StructWithUnion* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::StructWithUnion>::read(Protocol* proto,   ::cpp2::StructWithUnion* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::StructWithUnion>::serializedSize(Protocol* proto, const  ::cpp2::StructWithUnion* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::StructWithUnion>::serializedSizeZC(Protocol* proto, const  ::cpp2::StructWithUnion* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

class RecursiveStruct : private boost::totally_ordered<RecursiveStruct> {
 public:

  RecursiveStruct() {}
  // FragileConstructor for use in initialization lists only

  RecursiveStruct(apache::thrift::FragileConstructor, std::vector< ::cpp2::RecursiveStruct> mes__arg) :
      mes(std::move(mes__arg)) {}

  RecursiveStruct(RecursiveStruct&&) = default;

  RecursiveStruct(const RecursiveStruct&) = default;

  RecursiveStruct& operator=(RecursiveStruct&&) = default;

  RecursiveStruct& operator=(const RecursiveStruct&) = default;
  void __clear();

  virtual ~RecursiveStruct() throw() {}

  std::vector< ::cpp2::RecursiveStruct> mes;

  struct __isset {
    __isset() {
      __clear();
    }

    void __clear() {
      mes = false;
    }

    bool mes;
  } __isset;
  bool operator==(const RecursiveStruct& rhs) const;
  bool operator < (const RecursiveStruct& rhs) const;
  const std::vector< ::cpp2::RecursiveStruct>* get_mes() const&;
  std::vector< ::cpp2::RecursiveStruct>* get_mes() &;
  std::vector< ::cpp2::RecursiveStruct>* get_mes() && = delete;
  template <typename T>
  void set_mes(T&& mes_);

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;
};

void swap(RecursiveStruct& a, RecursiveStruct& b);

} // cpp2
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::cpp2::RecursiveStruct>::clear( ::cpp2::RecursiveStruct* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::cpp2::RecursiveStruct>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::RecursiveStruct>::write(Protocol* proto, const  ::cpp2::RecursiveStruct* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::RecursiveStruct>::read(Protocol* proto,   ::cpp2::RecursiveStruct* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::RecursiveStruct>::serializedSize(Protocol* proto, const  ::cpp2::RecursiveStruct* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> inline uint32_t Cpp2Ops< ::cpp2::RecursiveStruct>::serializedSizeZC(Protocol* proto, const  ::cpp2::RecursiveStruct* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace cpp2 {

} // cpp2