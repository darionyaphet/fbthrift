/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

use crate::ApplicationException;
use failure::Error;
use thiserror::Error;

#[derive(Debug, Error)]
#[allow(dead_code)]
pub enum ProtocolError {
    #[error("end of file reached")]
    EOF,
    #[error("bad thrift version specified")]
    BadVersion,
    #[error("missing protocol version")]
    ProtocolVersionMissing,
    #[error("protocol skip depth exceeded")]
    SkipDepthExceeded,
    #[error("streams unsupported")]
    StreamUnsupported,
    #[error("STOP outside of struct in skip")]
    UnexpectedStopInSkip,
    #[error("Unknown or invalid protocol ID {0}")]
    InvalidProtocolID(i16),
    #[error("Unknown or invalid TMessage type {0}")]
    InvalidMessageType(u32),
    #[error("Unknown or invalid type tag")]
    InvalidTypeTag,
    #[error("Unknown or invalid data length")]
    InvalidDataLength,
    #[error("Invalid value for type")]
    InvalidValue,
    #[error("Application exception: {0:?}")]
    ApplicationException(ApplicationException),
}

impl From<ApplicationException> for Error {
    fn from(exn: ApplicationException) -> Error {
        ProtocolError::ApplicationException(exn).into()
    }
}
