// GENERATED FROM interfaces/schema — DO NOT EDIT
// Source: CompletedEvent.schema.json, CompletedStatus.schema.json, ErrorType.schema.json, NotifyErrorEvent.schema.json, NotifyEventPayload.schema.json
// Generator: scripts/Generator/Program.cs

using System;
using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace OpenRoIS.Interfaces.Service
{
    // ─── Shared type definitions ($defs) ─────────────────────────────


    /// <summary>
    /// Status of a completed command execution.
    /// 
    /// Maps to RoIS_Service::Completed_Status in the IDL.
    /// 
    /// OK: Command completed successfully.
    /// ERROR: Command completed with an error.
    /// ABORT: Command was aborted.
    /// OUT_OF_RESOURCES: Command failed due to resource exhaustion.
    /// TIMEOUT: Command timed out before completion.
    /// </summary>
    public enum CompletedStatus
    {
        OK,
        ERROR,
        ABORT,
        OUT_OF_RESOURCES,
        TIMEOUT
    }

    /// <summary>
    /// Classification of error notifications.
    /// 
    /// Maps to RoIS_Service::ErrorType in the IDL.
    /// 
    /// ENGINE_INTERNAL_ERROR: Error originating from the HRI Engine itself.
    /// COMPONENT_INTERNAL_ERROR: Error originating from a component.
    /// COMPONENT_NOT_RESPONDING: A component failed to respond within timeout.
    /// USER_DEFINED_ERROR: Application-specific error.
    /// </summary>
    public enum ErrorType
    {
        ENGINE_INTERNAL_ERROR,
        COMPONENT_INTERNAL_ERROR,
        COMPONENT_NOT_RESPONDING,
        USER_DEFINED_ERROR
    }




    /// <summary>
    /// Event payload for ServiceApplicationBase::completed.
    /// 
    /// Attributes:
    ///     command_id: The command identifier that completed.
    ///     status: The completion status.
    /// </summary>
    public sealed class CompletedEvent : IEquatable<CompletedEvent>
    {
        [JsonPropertyName("command_id")]
        public string CommandId { get; }
        [JsonPropertyName("status")]
        public CompletedStatus Status { get; }

        public CompletedEvent(string commandId, CompletedStatus status)
        {
            CommandId = commandId;
            Status = status;
        }

        public bool Equals(CompletedEvent? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(CommandId, other.CommandId) && Equals(Status, other.Status);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as CompletedEvent);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(CommandId, Status);
        }

        public static bool operator ==(CompletedEvent? left, CompletedEvent? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(CompletedEvent? left, CompletedEvent? right)
            => !(left == right);
    }

    /// <summary>
    /// Event payload for ServiceApplicationBase::notify_error.
    /// 
    /// Attributes:
    ///     error_id: Unique identifier for this error instance.
    ///     error_type: Classification of the error.
    /// </summary>
    public sealed class NotifyErrorEvent : IEquatable<NotifyErrorEvent>
    {
        [JsonPropertyName("error_id")]
        public string ErrorId { get; }
        [JsonPropertyName("error_type")]
        public ErrorType ErrorType { get; }

        public NotifyErrorEvent(string errorId, ErrorType errorType)
        {
            ErrorId = errorId;
            ErrorType = errorType;
        }

        public bool Equals(NotifyErrorEvent? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(ErrorId, other.ErrorId) && Equals(ErrorType, other.ErrorType);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NotifyErrorEvent);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(ErrorId, ErrorType);
        }

        public static bool operator ==(NotifyErrorEvent? left, NotifyErrorEvent? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NotifyErrorEvent? left, NotifyErrorEvent? right)
            => !(left == right);
    }

    /// <summary>
    /// Event payload for ServiceApplicationBase::notify_event.
    /// 
    /// Attributes:
    ///     event_id: Unique identifier for this event occurrence.
    ///     event_type: The type of event (e.g., 'person_detected', 'face_localized').
    ///     subscribe_id: The subscription identifier that this event matches.
    ///     expire: ISO 8601 datetime when this event expires, or empty if no expiry.
    /// </summary>
    public sealed class NotifyEventPayload : IEquatable<NotifyEventPayload>
    {
        [JsonPropertyName("event_id")]
        public string EventId { get; }
        [JsonPropertyName("event_type")]
        public string EventType { get; }
        [JsonPropertyName("subscribe_id")]
        public string SubscribeId { get; }
        [JsonPropertyName("expire")]
        public string Expire { get; }

        public NotifyEventPayload(string eventId, string eventType, string subscribeId, string expire = "")
        {
            EventId = eventId;
            EventType = eventType;
            SubscribeId = subscribeId;
            Expire = expire;
        }

        public bool Equals(NotifyEventPayload? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(EventId, other.EventId) && Equals(EventType, other.EventType) && Equals(SubscribeId, other.SubscribeId) && Equals(Expire, other.Expire);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NotifyEventPayload);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(EventId, EventType, SubscribeId, Expire);
        }

        public static bool operator ==(NotifyEventPayload? left, NotifyEventPayload? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NotifyEventPayload? left, NotifyEventPayload? right)
            => !(left == right);
    }

}
