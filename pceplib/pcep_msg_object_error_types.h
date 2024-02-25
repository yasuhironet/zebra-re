// SPDX-License-Identifier: LGPL-2.1-or-later
/*
 * This file is part of the PCEPlib, a PCEP protocol library.
 *
 * Copyright (C) 2020 Volta Networks https://voltanet.io/
 *
 * Author : Brady Johnson <brady@voltanet.io>
 */


/*
 * Error Object Type and Value definitions
 */

#ifndef PCEP_OBJECT_ERROR_TYPES_H
#define PCEP_OBJECT_ERROR_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_ERROR_TYPE  30
#define MAX_ERROR_VALUE 255

  enum pcep_error_type
  {
    PCEP_ERRT_SESSION_FAILURE = 1,
    PCEP_ERRT_CAPABILITY_NOT_SUPPORTED = 2,
    PCEP_ERRT_UNKNOW_OBJECT = 3,
    PCEP_ERRT_NOT_SUPPORTED_OBJECT = 4,
    PCEP_ERRT_POLICY_VIOLATION = 5,
    PCEP_ERRT_MANDATORY_OBJECT_MISSING = 6,
    PCEP_ERRT_SYNC_PC_REQ_MISSING = 7,
    PCEP_ERRT_UNKNOWN_REQ_REF = 8,
    PCEP_ERRT_ATTEMPT_TO_ESTABLISH_2ND_PCEP_SESSION = 9,
    PCEP_ERRT_RECEPTION_OF_INV_OBJECT = 10,

    PCEP_ERRT_UNRECOGNIZED_EXRS_SUBOBJ = 11,
    PCEP_ERRT_DIFFSERV_AWARE_TE_ERROR = 12,
    PCEP_ERRT_BRPC_PROC_COMPLETION_ERROR = 13,
    PCEP_ERRT_UNASSIGNED14 = 14,
    PCEP_ERRT_GLOBAL_CONCURRENT_ERROR = 15,
    PCEP_ERRT_P2PMP_CAP_ERROR = 16,
    PCEP_ERRT_P2P_ENDPOINTS_ERROR = 17,
    PCEP_ERRT_P2P_FRAGMENTATION_ERROR = 18,
    PCEP_ERRT_INVALID_OPERATION = 19,
    PCEP_ERRT_LSP_STATE_SYNC_ERROR = 20,

    PCEP_ERRT_INVALID_TE_PATH_SETUP_TYPE = 21,
    PCEP_ERRT_UNASSIGNED22 = 22,
    PCEP_ERRT_BAD_PARAMETER_VALUE = 23,
    PCEP_ERRT_LSP_INSTANTIATE_ERROR = 24,
    PCEP_ERRT_START_TLS_FAILURE = 25,
    PCEP_ERRT_ASSOCIATION_ERROR = 26,
    PCEP_ERRT_WSON_RWA_ERROR = 27,
    PCEP_ERRT_H_PCE_ERROR = 28,
    PCEP_ERRT_PATH_COMP_FAILURE = 29,
    PCEP_ERRT_UNASSIGNED30 = 30 /* 30 - 255 Unassigned */
  };

  enum pcep_error_value
  {
    /* Error Value for Error Types that do not use an Error Value:
     * PCEP_ERRT_CAPABILITY_NOT_SUPPORTED=2
     * PCEP_ERRT_SYNC_PC_REQ_MISSING=7
     * PCEP_ERRT_UNKNOWN_REQ_REF=8
     * PCEP_ERRT_ATTEMPT_TO_ESTABLISH_2ND_PCEP_SESSION=9
     * PCEP_ERRT_UNRECOGNIZED_EXRS_SUBOBJ=11 */
    PCEP_ERRV_UNASSIGNED = 0,

    /* Error Values for PCEP_ERRT_SESSION_FAILURE=1 */
    PCEP_ERRV_RECVD_INVALID_OPEN_MSG = 1,
    PCEP_ERRV_OPENWAIT_TIMED_OUT = 2,
    PCEP_ERRV_UNACCEPTABLE_OPEN_MSG_NO_NEG = 3,
    PCEP_ERRV_UNACCEPTABLE_OPEN_MSG_NEG = 4,
    PCEP_ERRV_RECVD_SECOND_OPEN_MSG_UNACCEPTABLE = 5,
    PCEP_ERRV_RECVD_PCERR = 6,
    PCEP_ERRV_KEEPALIVEWAIT_TIMED_OUT = 7,
    PCEP_ERRV_PCEP_VERSION_NOT_SUPPORTED = 8,

    /* Error Values for PCEP_ERRT_UNKNOW_OBJECT=3 */
    PCEP_ERRV_UNREC_OBJECT_CLASS = 1,
    PCEP_ERRV_UNREC_OBJECT_TYPE = 2,

    /* Error Values for PCEP_ERRT_NOT_SUPPORTED_OBJECT=4 */
    PCEP_ERRV_NOT_SUPPORTED_OBJECT_CLASS = 1,
    PCEP_ERRV_NOT_SUPPORTED_OBJECT_TYPE = 2,
    /* 3: Unassigned */
    PCEP_ERRV_UNSUPPORTED_PARAM = 4,
    PCEP_ERRV_UNSUPPORTED_NW_PERF_CONSTRAINT = 5,
    PCEP_ERRV_NOT_SUPPORTED_BW_OBJECT_3_4 = 6,
    PCEP_ERRV_UNSUPPORTED_ENDPOINT_TYPE = 7,
    PCEP_ERRV_UNSUPPORTED_ENDPOINT_TLV = 8,
    PCEP_ERRV_UNSUPPORTED_RP_FLAG_GRANULARITY = 9,

    /* Error Values for PCEP_ERRT_POLICY_VIOLATION=5 */
    PCEP_ERRV_C_BIT_SET_IN_METRIC_OBJECT = 1,
    PCEP_ERRV_O_BIT_CLEARD_IN_RP_OBJECT = 2,
    PCEP_ERRV_OBJECTIVE_FUNC_NOT_ALLOWED = 3,
    PCEP_ERRV_RP_OF_BIT_SET = 4,
    PCEP_ERRV_GLOBAL_CONCURRENCY_NOT_ALLOWED = 5,
    PCEP_ERRV_MONITORING_MSG_REJECTED = 6,
    PCEP_ERRV_P2MP_PATH_COMP_NOT_ALLOWED = 7,
    PCEP_ERRV_UNALLOWED_NW_PERF_CONSTRAINT = 8,

    /* Error Values for PCEP_ERRT_MANDATORY_OBJECT_MISSING=6 */
    PCEP_ERRV_RP_OBJECT_MISSING = 1,
    PCEP_ERRV_RRO_OBJECT_MISSING_FOR_REOP = 2,
    PCEP_ERRV_EP_OBJECT_MISSING = 3,
    PCEP_ERRV_MONITOR_OBJECT_MISSING = 4,
    /* 5 - 7 Unassigned */
    PCEP_ERRV_LSP_OBJECT_MISSING = 8,
    PCEP_ERRV_ERO_OBJECT_MISSING = 9,
    PCEP_ERRV_SRP_OBJECT_MISSING = 10,
    PCEP_ERRV_LSP_ID_TLV_MISSING = 11,
    PCEP_ERRV_LSP_DB_TLV_MISSING = 12,
    PCEP_ERRV_S2LS_OBJECT_MISSING = 13,
    PCEP_ERRV_P2MP_LSP_ID_TLV_MISSING = 14,
    PCEP_ERRV_DISJOINTED_CONF_TLV_MISSING = 15,

    /* Error Values for PCEP_ERRT_RECEPTION_OF_INV_OBJECT=10 */
    PCEP_ERRV_P_FLAG_NOT_CORRECT_IN_OBJECT = 1,
    PCEP_ERRV_BAD_LABEL_VALUE = 2,
    PCEP_ERRV_UNSUPPORTED_NUM_SR_ERO_SUBOBJECTS = 3,
    PCEP_ERRV_BAD_LABEL_FORMAT = 4,
    PCEP_ERRV_ERO_SR_ERO_MIX = 5,
    PCEP_ERRV_SR_ERO_SID_NAI_ABSENT = 6,
    PCEP_ERRV_SR_RRO_SID_NAI_ABSENT = 7,
    PCEP_ERRV_SYMBOLIC_PATH_NAME_TLV_MISSING = 8,
    PCEP_ERRV_MSD_EXCEEDS_PCEP_SESSION_MAX = 9,

    PCEP_ERRV_RRO_SR_RRO_MIX = 10,
    PCEP_ERRV_MALFORMED_OBJECT = 11,
    PCEP_ERRV_MISSING_PCE_SR_CAP_TLV = 12,
    PCEP_ERRV_UNSUPPORTED_NAI = 13,
    PCEP_ERRV_UNKNOWN_SID = 14,
    PCEP_ERRV_CANNOT_RESOLVE_NAI_TO_SID = 15,
    PCEP_ERRV_COULD_NOT_FIND_SRGB = 16,
    PCEP_ERRV_SID_EXCEEDS_SRGB = 17,
    PCEP_ERRV_COULD_NOT_FIND_SRLB = 18,
    PCEP_ERRV_SID_EXCEEDS_SRLB = 19,

    PCEP_ERRV_INCONSISTENT_SID = 20,
    PCEP_ERRV_MSD_MUST_BE_NONZERO = 21,
    PCEP_ERRV_MISMATCH_O_S2LS_LSP = 22,
    PCEP_ERRV_INCOMPATIBLE_H_PCE_OF = 23,
    PCEP_ERRV_BAD_BANDWIDTH_TYPE_3_4 = 24,
    PCEP_ERRV_UNSUPPORTED_LSP_PROT_FLAGS = 25,
    PCEP_ERRV_UNSUPPORTED_2ND_LSP_PROT_FLAGS = 26,
    PCEP_ERRV_UNSUPPORTED_LINK_PROT_TYPE = 27,
    PCEP_ERRV_LABEL_SET_TLV_NO_RP_R = 28,
    PCEP_ERRV_WRONG_LABEL_SET_TLV_O_L_SET = 29,

    PCEP_ERRV_WRONG_LABEL_SET_O_SET = 30,
    PCEP_ERRV_MISSING_GMPLS_CAP_TLV = 31,
    PCEP_ERRV_INCOMPATIBLE_OF_CODE = 32,

    /* PCEP_ERRT_DIFFSERV_AWARE_TE_ERROR = 12 */
    PCEP_ERRV_UNSUPPORTED_CLASS_TYPE = 1,
    PCEP_ERRV_INVALID_CLASS_TYPE = 2,
    PCEP_ERRV_CLASS_SETUP_TYPE_NOT_TE_CLASS = 3,

    /* PCEP_ERRT_BRPC_PROC_COMPLETION_ERROR = 13 */
    PCEP_ERRV_BRPC_PROC_NOT_SUPPORTED = 1,

    /* PCEP_ERRT_UNASSIGNED14 = 14 */

    /* PCEP_ERRT_GLOBAL_CONCURRENT_ERROR = 15 */
    PCEP_ERRV_INSUFFICIENT_MEMORY = 1,
    PCEP_ERRV_GLOBAL_CONCURRENT_OPT_NOT_SUPPORTED = 2,

    /* PCEP_ERRT_P2PMP_CAP_ERROR = 16 */
    PCEP_ERRV_PCE_INSUFFICIENT_MEMORY = 1,
    PCEP_ERRV_PCE_NOT_CAPABLE_P2MP_COMP = 2,

    /* PCEP_ERRT_P2P_ENDPOINTS_ERROR = 17 */
    PCEP_ERRV_NO_EP_WITH_LEAF_TYPE2 = 1,
    PCEP_ERRV_NO_EP_WITH_LEAF_TYPE3 = 2,
    PCEP_ERRV_NO_EP_WITH_LEAF_TYPE4 = 3,
    PCEP_ERRV_INCONSITENT_EP = 4,

    /* PCEP_ERRT_P2P_FRAGMENTATION_ERROR = 18 */
    PCEP_ERRV_FRAG_REQUEST_FAILURE = 1,
    PCEP_ERRV_FRAG_REPORT_FAILURE = 2,
    PCEP_ERRV_FRAG_UPDATE_FAILURE = 3,
    PCEP_ERRV_FRAG_INSTANTIATION_FAILURE = 4,

    /* Error Values for PCEP_ERRT_INVALID_OPERATION=19 */
    PCEP_ERRV_LSP_UPDATE_FOR_NON_DELEGATED_LSP = 1,
    PCEP_ERRV_LSP_UPDATE_NON_ADVERTISED_PCE = 2,
    PCEP_ERRV_LSP_UPDATE_UNKNOWN_PLSP_ID = 3,
    /* 4: unassigned */
    PCEP_ERRV_LSP_REPORT_NON_ADVERTISED_PCE = 5,
    PCEP_ERRV_PCE_INIT_LSP_LIMIT_REACHED = 6,
    PCEP_ERRV_PCE_INIT_LSP_DELEGATION_CANT_REVOKE = 7,
    PCEP_ERRV_LSP_INIT_NON_ZERO_PLSP_ID = 8,
    PCEP_ERRV_LSP_NOT_PCE_INITIATED = 9,
    PCEP_ERRV_PCE_INIT_OP_FREQ_LIMIT_REACHED = 10,
    PCEP_ERRV_LSP_REPORT_P2MP_NOT_ADVERTISED = 11,
    PCEP_ERRV_LSP_UPDATE_P2MP_NOT_ADVERTISED = 12,
    PCEP_ERRV_LSP_INSTANTIATION_P2MP_NOT_ADVERTISED = 13,
    PCEP_ERRV_AUTO_BW_CAP_NOT_ADVERTISED = 14,

    /* Error Values for PCEP_ERRT_LSP_STATE_SYNC_ERROR=20 */
    PCEP_ERRV_PCE_CANT_PROCESS_LSP_REPORT = 1,
    PCEP_ERRV_LSP_DB_VERSION_MISMATCH = 2,
    PCEP_ERRV_TRIGGER_ATTEMPT_BEFORE_PCE_TRIGGER = 3,
    PCEP_ERRV_TRIGGER_ATTEMPT_NO_PCE_TRIGGER_CAP = 4,
    PCEP_ERRV_PCC_CANT_COMPLETE_STATE_SYNC = 5,
    PCEP_ERRV_INVALID_LSP_DB_VERSION_NUMBER = 6,
    PCEP_ERRV_INVALID_SPEAKER_ENTITY_ID = 7,

    /* PCEP_ERRT_INVALID_TE_PATH_SETUP_TYPE = 21 */
    PCEP_ERRV_UNSUPPORTED_PATH_SETUP_TYPE = 1,
    PCEP_ERRV_MISMATCHED_PATH_SETUP_TYPE = 2,

    /* PCEP_ERRT_UNASSIGNED22 = 22 */

    /* Error Values for PCEP_ERRT_BAD_PARAMETER_VALUE=23 */
    PCEP_ERRV_SYMBOLIC_PATH_NAME_IN_USE = 1,
    PCEP_ERRV_LSP_SPEAKER_ID_NOT_PCE_INITIATED = 2,

    /* Error Values for PCEP_ERRT_LSP_INSTANTIATE_ERROR=24 */
    PCEP_ERRV_UNACCEPTABLE_INSTANTIATE_ERROR = 1,
    PCEP_ERRV_INTERNAL_ERROR = 2,
    PCEP_ERRV_SIGNALLING_ERROR = 3,

    /* PCEP_ERRT_START_TLS_FAILURE = 25 */
    PCEP_ERRV_START_TLS_AFTER_PCEP_EXCHANGE = 1,
    PCEP_ERRV_MSG_NOT_START_TLS_OPEN_ERROR = 2,
    PCEP_ERRV_CONNECTION_WO_TLS_NOT_POSSIBLE = 3,
    PCEP_ERRV_CONNECTION_WO_TLS_IS_POSSIBLE = 4,
    PCEP_ERRV_NO_START_TLS_BEFORE_START_TLS_WAIT_TIMER = 5,

    /* PCEP_ERRT_ASSOCIATION_ERROR = 26 */
    PCEP_ERRV_ASSOC_TYPE_NOT_SUPPORTED = 1,
    PCEP_ERRV_TOO_MANY_LSPS_IN_ASSOC_GRP = 2,
    PCEP_ERRV_TOO_MANY_ASSOC_GROUPS = 3,
    PCEP_ERRV_ASSOCIATION_UNKNOWN = 4,
    PCEP_ERRV_OP_CONF_ASSOC_INFO_MISMATCH = 5,
    PCEP_ERRV_ASSOC_INFO_MISMATCH = 6,
    PCEP_ERRV_CANNOT_JOIN_ASSOC_GROUP = 7,
    PCEP_ERRV_ASSOC_ID_NOT_IN_RANGE = 8,
    PCEP_ERRV_TUNNEL_EP_MISMATCH_PATH_PROT_ASSOC = 9,
    PCEP_ERRV_ATTEMPTED_ADD_LSP_PATH_PROT_ASSOC = 10,
    PCEP_ERRV_PROTECTION_TYPE_NOT_SUPPORTED = 11,

    /* PCEP_ERRT_WSON_RWA_ERROR = 27 */
    PCEP_ERRV_RWA_INSUFFICIENT_MEMORY = 1,
    PCEP_ERRV_RWA_COMP_NOT_SUPPORTED = 2,
    PCEP_ERRV_SYNTAX_ENC_ERROR = 3,

    /* PCEP_ERRT_H_PCE_ERROR = 28 */
    PCEP_ERRV_H_PCE_CAP_NOT_ADVERTISED = 1,
    PCEP_ERRV_PARENT_PCE_CAP_CANT_BE_PROVIDED = 2,

    /* PCEP_ERRT_PATH_COMP_FAILURE = 29 */
    PCEP_ERRV_UNACCEPTABLE_REQUEST_MSG = 1,
    PCEP_ERRV_GENERALIZED_BW_VAL_NOT_SUPPORTED = 2,
    PCEP_ERRV_LABEL_SET_CONSTRAINT_COULD_NOT_BE_MET = 3,
    PCEP_ERRV_LABEL_CONSTRAINT_COULD_NOT_BE_MET = 4,

  };

  const char *get_error_type_str (enum pcep_error_type error_type);
  const char *get_error_value_str (enum pcep_error_type error_type,
                                   enum pcep_error_value error_value);


#ifdef __cplusplus
}
#endif

#endif
