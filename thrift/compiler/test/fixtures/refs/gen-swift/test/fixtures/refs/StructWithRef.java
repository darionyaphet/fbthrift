/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.refs;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct(value="StructWithRef", builder=StructWithRef.Builder.class)
public final class StructWithRef {
    @ThriftConstructor
    public StructWithRef(
        @ThriftField(value=1, name="def_field", requiredness=Requiredness.NONE) final test.fixtures.refs.Empty defField,
        @ThriftField(value=2, name="opt_field", requiredness=Requiredness.OPTIONAL) final test.fixtures.refs.Empty optField,
        @ThriftField(value=3, name="req_field", requiredness=Requiredness.REQUIRED) final test.fixtures.refs.Empty reqField
    ) {
        this.defField = defField;
        this.optField = optField;
        this.reqField = reqField;
    }
    
    @ThriftConstructor
    protected StructWithRef() {
      this.defField = null;
      this.optField = null;
      this.reqField = null;
    }
    
    public static class Builder {
        private test.fixtures.refs.Empty defField;
        @ThriftField(value=1, name="def_field", requiredness=Requiredness.NONE)
        public Builder setDefField(test.fixtures.refs.Empty defField) {
            this.defField = defField;
            return this;
        }
        private test.fixtures.refs.Empty optField;
        @ThriftField(value=2, name="opt_field", requiredness=Requiredness.OPTIONAL)
        public Builder setOptField(test.fixtures.refs.Empty optField) {
            this.optField = optField;
            return this;
        }
        private test.fixtures.refs.Empty reqField;
        @ThriftField(value=3, name="req_field", requiredness=Requiredness.REQUIRED)
        public Builder setReqField(test.fixtures.refs.Empty reqField) {
            this.reqField = reqField;
            return this;
        }
    
        public Builder() { }
        public Builder(StructWithRef other) {
            this.defField = other.defField;
            this.optField = other.optField;
            this.reqField = other.reqField;
        }
    
        @ThriftConstructor
        public StructWithRef build() {
            return new StructWithRef (
                this.defField,
                this.optField,
                this.reqField
            );
        }
    }
    
    private final test.fixtures.refs.Empty defField;
    private final test.fixtures.refs.Empty optField;
    private final test.fixtures.refs.Empty reqField;

    
    @ThriftField(value=1, name="def_field", requiredness=Requiredness.NONE)
    public test.fixtures.refs.Empty getDefField() { return defField; }
        
    @ThriftField(value=2, name="opt_field", requiredness=Requiredness.OPTIONAL)
    public test.fixtures.refs.Empty getOptField() { return optField; }
        
    @ThriftField(value=3, name="req_field", requiredness=Requiredness.REQUIRED)
    public test.fixtures.refs.Empty getReqField() { return reqField; }
    
    @Override
    public String toString() {
        return toStringHelper(this)
            .add("defField", defField)
            .add("optField", optField)
            .add("reqField", reqField)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        StructWithRef other = (StructWithRef)o;
    
        return
            Objects.equals(defField, other.defField) &&
            Objects.equals(optField, other.optField) &&
            Objects.equals(reqField, other.reqField) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            defField,
            optField,
            reqField
        });
    }
    
}
