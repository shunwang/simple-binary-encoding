/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _FRAMECODEC_HPP_
#define _FRAMECODEC_HPP_

/* math.h needed for NAN */
#include <math.h>
#include "sbe/sbe.hpp"

#include "uk_co_real_logic_sbe_ir_generated/VarDataEncoding.hpp"
#include "uk_co_real_logic_sbe_ir_generated/ByteOrderCodec.hpp"
#include "uk_co_real_logic_sbe_ir_generated/PresenceCodec.hpp"
#include "uk_co_real_logic_sbe_ir_generated/PrimitiveTypeCodec.hpp"
#include "uk_co_real_logic_sbe_ir_generated/SignalCodec.hpp"

using namespace sbe;

namespace uk_co_real_logic_sbe_ir_generated {

class FrameCodec
{
private:
    char *buffer_;
    int *positionPtr_;
    int offset_;
    int position_;
    int actingBlockLength_;
    int actingVersion_;

public:

    static sbe_uint16_t blockLength(void)
    {
        return (sbe_uint16_t)8;
    }

    static sbe_uint16_t templateId(void)
    {
        return (sbe_uint16_t)1;
    }

    static sbe_uint8_t templateVersion(void)
    {
        return (sbe_uint8_t)0;
    }

    sbe_uint64_t offset(void) const
    {
        return offset_;
    }

    FrameCodec &wrapForEncode(char *buffer, const int offset)
    {
        buffer_ = buffer;
        offset_ = offset;
        actingBlockLength_ = blockLength();
        actingVersion_ = templateVersion();
        position(offset + actingBlockLength_);
        positionPtr_ = &position_;
        return *this;
    }

    FrameCodec &wrapForDecode(char *buffer, const int offset,
                        const int actingBlockLength, const int actingVersion)
    {
        buffer_ = buffer;
        offset_ = offset;
        actingBlockLength_ = actingBlockLength;
        actingVersion_ = actingVersion;
        positionPtr_ = &position_;
        position(offset + actingBlockLength_);
        return *this;
    }

    sbe_uint64_t position(void) const
    {
        return position_;
    }

    void position(const sbe_uint64_t position)
    {
        position_ = position;
    }

    int size(void) const
    {
        return position() - offset_;
    }

    char *buffer(void)
    {
        return buffer_;
    }

    int actingVersion(void) const
    {
        return actingVersion_;
    }

    static int sbeIrVersionSchemaId(void)
    {
        return 1;
    }

    static int sbeIrVersionSinceVersion(void)
    {
         return 0;
    }

    bool sbeIrVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *sbeIrVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static sbe_int32_t sbeIrVersionNullValue()
    {
        return -2147483648;
    }

    static sbe_int32_t sbeIrVersionMinValue()
    {
        return -2147483647;
    }

    static sbe_int32_t sbeIrVersionMaxValue()
    {
        return 2147483647;
    }

    sbe_int32_t sbeIrVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 0)));
    }

    FrameCodec &sbeIrVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 0)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static int schemaVersionSchemaId(void)
    {
        return 2;
    }

    static int schemaVersionSinceVersion(void)
    {
         return 0;
    }

    bool schemaVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }


    static const char *schemaVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    static sbe_int32_t schemaVersionNullValue()
    {
        return -2147483648;
    }

    static sbe_int32_t schemaVersionMinValue()
    {
        return -2147483647;
    }

    static sbe_int32_t schemaVersionMaxValue()
    {
        return 2147483647;
    }

    sbe_int32_t schemaVersion(void) const
    {
        return SBE_LITTLE_ENDIAN_ENCODE_32(*((sbe_int32_t *)(buffer_ + offset_ + 4)));
    }

    FrameCodec &schemaVersion(const sbe_int32_t value)
    {
        *((sbe_int32_t *)(buffer_ + offset_ + 4)) = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        return *this;
    }

    static const char *packageNameCharacterEncoding()
    {
        return "UTF-8";
    }

    static int packageNameSinceVersion(void)
    {
         return 0;
    }

    bool packageNameInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static int packageNameSchemaId(void)
    {
        return 3;
    }


    static const char *packageNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    sbe_int64_t packageNameLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *packageName(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getPackageName(char *dst, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + sizeOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        ::memcpy(dst, buffer_ + position(), bytesToCopy);
        position(position() + (sbe_uint64_t)dataLength);
        return bytesToCopy;
    }

    int putPackageName(const char *src, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        position(lengthPosition + sizeOfLengthField);
        ::memcpy(buffer_ + position(), src, length);
        position(position() + (sbe_uint64_t)length);
        return length;
    }

    static const char *namespaceNameCharacterEncoding()
    {
        return "UTF-8";
    }

    static int namespaceNameSinceVersion(void)
    {
         return 0;
    }

    bool namespaceNameInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static int namespaceNameSchemaId(void)
    {
        return 4;
    }


    static const char *namespaceNameMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    sbe_int64_t namespaceNameLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *namespaceName(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getNamespaceName(char *dst, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + sizeOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        ::memcpy(dst, buffer_ + position(), bytesToCopy);
        position(position() + (sbe_uint64_t)dataLength);
        return bytesToCopy;
    }

    int putNamespaceName(const char *src, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        position(lengthPosition + sizeOfLengthField);
        ::memcpy(buffer_ + position(), src, length);
        position(position() + (sbe_uint64_t)length);
        return length;
    }

    static const char *semanticVersionCharacterEncoding()
    {
        return "UTF-8";
    }

    static int semanticVersionSinceVersion(void)
    {
         return 0;
    }

    bool semanticVersionInActingVersion(void)
    {
        return (actingVersion_ >= 0) ? true : false;
    }

    static int semanticVersionSchemaId(void)
    {
        return 5;
    }


    static const char *semanticVersionMetaAttribute(const MetaAttribute::Attribute metaAttribute)
    {
        switch (metaAttribute)
        {
            case MetaAttribute::EPOCH: return "unix";
            case MetaAttribute::TIME_UNIT: return "nanosecond";
            case MetaAttribute::SEMANTIC_TYPE: return "";
        }

        return "";
    }

    sbe_int64_t semanticVersionLength(void) const
    {
        return (*((sbe_uint8_t *)(buffer_ + position())));
    }

    const char *semanticVersion(void)
    {
         const char *fieldPtr = (buffer_ + position() + 1);
         position(position() + 1 + *((sbe_uint8_t *)(buffer_ + position())));
         return fieldPtr;
    }

    int getSemanticVersion(char *dst, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        position(lengthPosition + sizeOfLengthField);
        sbe_int64_t dataLength = (*((sbe_uint8_t *)(buffer_ + lengthPosition)));
        int bytesToCopy = (length < dataLength) ? length : dataLength;
        ::memcpy(dst, buffer_ + position(), bytesToCopy);
        position(position() + (sbe_uint64_t)dataLength);
        return bytesToCopy;
    }

    int putSemanticVersion(const char *src, const int length)
    {
        sbe_uint64_t sizeOfLengthField = 1;
        sbe_uint64_t lengthPosition = position();
        *((sbe_uint8_t *)(buffer_ + lengthPosition)) = ((sbe_uint8_t)length);
        position(lengthPosition + sizeOfLengthField);
        ::memcpy(buffer_ + position(), src, length);
        position(position() + (sbe_uint64_t)length);
        return length;
    }
};
}
#endif
