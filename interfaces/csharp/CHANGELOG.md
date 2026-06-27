# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/2.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- Target `netstandard2.1` for Unity 6.3+ compatibility.
- Enable `Nullable` in the `.csproj`.
- Generate `OpenRoIS.Interfaces` C# package from 38 JSON Schema files in `interfaces/schema/`.
- Emit C# `sealed class` types for all core HRI, Common, Service, Profile, Bus, and component models.
- Emit generated component models for `PersonDetection`, `Navigation`, and `SystemInformation`.
- Emit C# `enum` types for `ReturnCode`, `ComponentStatus`, `StreamStatus`, `CompletedStatus`, `ErrorType`.
- Emit `ICommandUnitSequenceItem` marker interface implemented by `CommandUnit` and `ConcurrentCommands`, so `CommandUnitSequence.CommandUnitList` is typed as `IReadOnlyList<ICommandUnitSequenceItem>?` for compile-time type safety of the command sequence union.
- Hand-write `IBusAdapter` interface, `EventSink` delegate, `BusAdapterError` and `ComponentNotFoundError` exception classes.

[unreleased]: https://github.com/openrois/openrois/compare/main...HEAD