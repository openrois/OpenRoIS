# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/2.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Target Python 3.12+ (aligns with ROS 2 Jazzy).
- Implement Pydantic models for all core RoIS types: `ReturnCode`, `Result`,
  `Parameter`, `Argument`, `CommandUnit`, `ConcurrentCommands`,
  `CommandUnitSequence` (hri); `ComponentStatus`, `StreamStatus` (common);
  `CompletedStatus`, `ErrorType`, `CompletedEvent`, `NotifyErrorEvent`,
  `NotifyEventPayload` (service); `RoISIdentifierType`, `ParameterProfile`,
  `MessageProfile`, `CommandMessageProfile`, `QueryMessageProfile`,
  `EventMessageProfile`, `HRIComponentProfile`, `HRIEngineProfileType`
  (profiles); `BusAdapter` protocol + request/response models (bus).
- Implement typed component models for `PersonDetection`, `Navigation`, and
  `SystemInformation`.
- Add `py.typed` marker (PEP 561) for downstream type checking.

[unreleased]: https://github.com/openrois/openrois/compare/main...HEAD