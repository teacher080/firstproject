/* Copyright (c) Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of other
 * contributors to this software may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * 4. This software must only be used in a processor manufactured by Nordic
 * Semiconductor ASA, or in a processor manufactured by a third party that
 * is used in combination with a processor manufactured by Nordic Semiconductor.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef BLE_GATTC_APP_H__
#define BLE_GATTC_APP_H__
/**@file
 *
 * @defgroup ble_gattc_app GATTC Application command request encoders and command response decoders
 * @{
 * @ingroup  ble_sdk_lib_serialization
 *
 * @brief    GATTC Application command request encoders and command response decoders.
 */
#include "ble_gattc.h"
#include "ble.h"

/**@brief Encodes @ref sd_ble_gattc_primary_services_discover command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_primary_services_discover_encoding for packet format,
 *     @ref ble_gattc_primary_services_discover_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      start_handle   Handle to start searching from.
 * @param[in]      p_srvc_uuid    Pointer to a @ref ble_uuid_t which indicates the service UUID to
 *                                be found. If it is NULL, all primary services will be returned.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_primary_services_discover_req_enc(uint16_t                 conn_handle,
                                                     uint16_t                 start_handle,
                                                     ble_uuid_t const * const p_srvc_uuid,
                                                     uint8_t * const          p_buf,
                                                     uint32_t *               p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_primary_services_discover command.
 *
 * @sa @ref nrf51_sd_ble_gattc_primary_services_discover_encoding for packet format,
 *     @ref ble_gattc_primary_services_discover_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_primary_services_discover_rsp_dec(uint8_t const * const p_buf,
                                                     uint32_t              packet_len,
                                                     uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_descriptors_discover command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_descriptors_discover_encoding for packet format,
 *     @ref ble_gattc_primary_descriptors_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_handle_range A pointer to the range of handles of the Service to perform
 *                                this procedure on.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_descriptors_discover_req_enc(
    uint16_t                               conn_handle,
    ble_gattc_handle_range_t const * const p_handle_range,
    uint8_t * const                        p_buf,
    uint32_t *                             p_buf_len);


/**@brief Decodes response to @ref sd_ble_gattc_descriptors_discover command.
 *
 * @sa @ref nrf51_sd_ble_gattc_descriptors_discover_encoding for packet format,
 *     @ref ble_gattc_primary_services_discover_rsp_dec for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_descriptors_discover_rsp_dec(uint8_t const * const p_buf,
                                                uint32_t              packet_len,
                                                uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_relationships_discover command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_relationships_discover_encoding for packet format,
 *     @ref ble_gattc_relationships_discover_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_handle_range A pointer to the range of handles of the Service to perform
 *                                this procedure on.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_relationships_discover_req_enc(
    uint16_t                               conn_handle,
    ble_gattc_handle_range_t const * const p_handle_range,
    uint8_t * const                        p_buf,
    uint32_t *                             p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_relationships_discover command.
 *
 * @sa @ref nrf51_sd_ble_gattc_relationships_discover_encoding for packet format,
 *     @ref ble_gattc_relationships_discover_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_relationships_discover_rsp_dec(uint8_t const * const p_buf,
                                                  uint32_t              packet_len,
                                                  uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_characteristics_discover command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_characteristics_discover_encoding for packet format,
 *     @ref ble_gattc_primary_characteristics_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_handle_range A pointer to the range of handles of the Service to perform
 *                                this procedure on.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_characteristics_discover_req_enc
    (uint16_t                              conn_handle,
    ble_gattc_handle_range_t const * const p_handle_range,
    uint8_t * const                        p_buf,
    uint32_t *                             p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_characteristics_discover command.
 *
 * @sa @ref nrf51_sd_ble_gattc_characteristics_discover_encoding for packet format,
 *     @ref ble_gattc_primary_services_discover_rsp_dec for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_characteristics_discover_rsp_dec(uint8_t const * const p_buf,
                                                    uint32_t              packet_len,
                                                    uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_read command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_read_encoding for packet format,
 *     @ref ble_gattc_read_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      Handle         The handle of the attribute to be read.
 * @param[in]      Offset         Offset into the attribute value to be read.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_read_req_enc(uint16_t        conn_handle,
                                uint16_t        handle,
                                uint16_t        offset,
                                uint8_t * const p_buf,
                                uint32_t *      p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_read command.
 *
 * @sa @ref nrf51_sd_ble_gattc_read_encoding for packet format,
 *     @ref ble_gattc_read_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_read_rsp_dec(uint8_t const * const p_buf,
                                uint32_t              packet_len,
                                uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_char_values_read command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_read_encoding for packet format,
 *     @ref ble_gattc_char_values_read_rsp_decc for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_handles      A pointer to the handle(s) of the attribute(s) to be read.
 * @param[in]      handle_count   The number of handles in p_handles.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_char_values_read_req_enc(uint16_t               conn_handle,
                                            uint16_t const * const p_handles,
                                            uint16_t               handle_count,
                                            uint8_t * const        p_buf,
                                            uint32_t *             p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_read command.
 *
 * @sa @ref nrf51_sd_ble_gattc_read_encoding for packet format,
 *     @ref ble_gattc_char_values_read_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_char_values_read_rsp_dec(uint8_t const * const p_buf,
                                            uint32_t              packet_len,
                                            uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_write command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_write_encoding for packet format,
 *     @ref ble_gattc_write_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_write_params Pointer to \ref GATTC Write params.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_write_req_enc(uint16_t                               conn_handle,
                                 ble_gattc_write_params_t const * const p_write_params,
                                 uint8_t * const                        p_buf,
                                 uint32_t *                             p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_write command.
 *
 * @sa @ref nrf51_sd_ble_gattc_write_encoding for packet format,
 *     @ref ble_gattc_write_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] result_code   Command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_write_rsp_dec(uint8_t const * const p_buf,
                                 uint32_t              packet_len,
                                 uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_hv_confirm command request.
 *
 * @sa @ref nrf51_sd_ble_gattc_hv_confirm_encoding for packet format,
 *     @ref ble_gattc_hv_confirm_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      handle         Handle of the attribute in the indication.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_hv_confirm_req_enc(uint16_t         conn_handle,
                                      uint16_t         handle,
                                      uint8_t * const  p_buf,
                                      uint32_t * const p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_hv_confirm command.
 *
 * @sa @ref nrf51_sd_ble_gattc_hv_confirm_encoding for packet format,
 *     @ref ble_gattc_hv_confirm_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] p_result_code   Pointer to command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_hv_confirm_rsp_dec(uint8_t const * const p_buf,
                                      uint32_t              packet_len,
                                      uint32_t * const      p_result_code);

/**@brief Encodes @ref sd_ble_gattc_char_value_by_uuid_read command request.
 *
 * @sa @ref nrf51_ssd_ble_gattc_char_value_by_uuid_read_encoding for packet format,
 *     @ref ble_gattc_char_value_by_uuid_read_rsp_dec for command response decoder.
 *
 * @param[in]      conn_handle    Connection handle of the connection.
 * @param[in]      p_uuid         Pointer to a characteristic value UUID to read.
 * @param[in]      p_handle_range Pointer to the range of handles to perform this procedure on.
 * @param[in]      p_buf          Pointer to buffer where encoded data command will be returned.
 * @param[in, out] p_buf_len      \c in: size of \p p_buf buffer.
 *                                \c out: Length of encoded command packet.
 *
 * @retval NRF_SUCCESS                Encoding success.
 * @retval NRF_ERROR_NULL             Encoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_INVALID_LENGTH   Encoding failure. Incorrect buffer length.
 */
uint32_t ble_gattc_char_value_by_uuid_read_req_enc
    (uint16_t                              conn_handle,
    ble_uuid_t const * const               p_uuid,
    ble_gattc_handle_range_t const * const p_handle_range,
    uint8_t * const                        p_buf,
    uint32_t * const                       p_buf_len);

/**@brief Decodes response to @ref sd_ble_gattc_char_value_by_uuid_read command.
 *
 * @sa @ref nrf51_sd_ble_gattc_char_value_by_uuid_read_encoding for packet format,
 *     @ref ble_gattc_char_value_by_uuid_read_req_enc for command request encoder.
 *
 * @param[in]  p_buf         Pointer to beginning of command response packet.
 * @param[in]  packet_len    Length (in bytes) of response packet.
 * @param[out] p_result_code Pointer to command response result code.
 *
 * @retval NRF_SUCCESS              Decoding success.
 * @retval NRF_ERROR_NULL           Decoding failure. NULL pointer supplied.
 * @retval NRF_ERROR_DATA_SIZE      Decoding failure. Incorrect buffer length.
 * @retval NRF_ERROR_INVALID_DATA   Decoding failure. Decoded operation code does not match expected
 *                                  operation code.
 */
uint32_t ble_gattc_char_value_by_uuid_read_rsp_dec(uint8_t const * const p_buf,
                                                   uint32_t              packet_len,
                                                   uint32_t * const      p_result_code);
/** @} */
#endif

