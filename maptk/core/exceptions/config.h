/*ckwg +5
 * Copyright 2011-2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef MAPTK_CORE_EXCEPTIONS_CONFIG_H
#define MAPTK_CORE_EXCEPTIONS_CONFIG_H

#include "base.h"

#include <maptk/core/types.h>

namespace maptk
{

/**
 * \brief The base class for all exceptions thrown from \ref config.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT configuration_exception
  : public maptk_core_base_exception
{
  public:
    /// Constructor.
    configuration_exception() MAPTK_NOTHROW;
    /// Destructor.
    virtual ~configuration_exception() MAPTK_NOTHROW;
};

/**
 * \brief The inner exception thrown when casting fails.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT bad_configuration_cast
  : public configuration_exception
{
  public:
    /**
     * \brief Constructor.
     * \param reason The reason for the bad cast.
     */
    bad_configuration_cast(char const* reason) MAPTK_NOTHROW;
    /// Destructor.
    virtual ~bad_configuration_cast() MAPTK_NOTHROW;
};

/**
 * \brief Thrown when a value cannot be converted to the requested type.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT bad_configuration_cast_exception
  : public configuration_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param key The key that was requested.
     * \param value The value that was failed to cast.
     * \param type The type that was requested.
     * \param reason The reason for the bad cast.
     */
    bad_configuration_cast_exception(config_key_t const& key,
                                     config_value_t const& value,
                                     char const* type,
                                     char const* reason) MAPTK_NOTHROW;
    /// Destructor.
    virtual ~bad_configuration_cast_exception() MAPTK_NOTHROW;

    /// The requested key name.
    config_key_t const m_key;
    /// The value of the requested key.
    config_value_t const m_value;
    /// The type requested for the cast.
    std::string const m_type;
    /// The reason for the failed cast.
    std::string const m_reason;
};

/**
 * \brief Thrown when a value is requested for a value which does not exist.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT no_such_configuration_value_exception
  : public configuration_exception
{
  public:
    /**
     * \brief Constructor.
     * \param key The key that was requested from the configuration.
     */
    no_such_configuration_value_exception(config_key_t const& key) MAPTK_NOTHROW;
    /// Destructor.
    virtual ~no_such_configuration_value_exception() MAPTK_NOTHROW;

    /// The requested key name.
    config_key_t const m_key;
};

/**
 * \brief Thrown when a value is set but is marked as read-only.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT set_on_read_only_value_exception
  : public configuration_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param key The key that was requested from the configuration.
     * \param value The current read-only value of \p key.
     * \param new_value The value that was attempted to be set.
     */
    set_on_read_only_value_exception(config_key_t const& key, config_value_t const& value, config_value_t const& new_value) MAPTK_NOTHROW;
    /**
     * \brief Destructor.
     */
    ~set_on_read_only_value_exception() MAPTK_NOTHROW;

    /// The requested key name.
    config_key_t const m_key;
    /// The existing value.
    config_value_t const m_value;
    /// The new value.
    config_value_t const m_new_value;
};

/**
 * \brief Thrown when a value is unset but is marked as read-only.
 * \ingroup exceptions
 */
class MAPTK_CORE_EXPORT unset_on_read_only_value_exception
  : public configuration_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param key The key that was requested from the configuration.
     * \param value The current value for \p key.
     */
    unset_on_read_only_value_exception(config_key_t const& key, config_value_t const& value) MAPTK_NOTHROW;
    /**
     * \brief Destructor.
     */
    ~unset_on_read_only_value_exception() MAPTK_NOTHROW;

    /// The requested key name.
    config_key_t const m_key;
    /// The existing value.
    config_value_t const m_value;
};

}

#endif // MAPTK_CORE_EXCEPTIONS_CONFIG_H
