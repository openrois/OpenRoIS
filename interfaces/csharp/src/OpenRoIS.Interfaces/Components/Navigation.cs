// GENERATED FROM interfaces/schema — DO NOT EDIT
// Source: NavigationGetParameterResult.schema.json, NavigationReachedTargetEvent.schema.json, NavigationSetParameter.schema.json, NavigationSetParameterResult.schema.json, NavigationStatusResult.schema.json
// Generator: scripts/Generator/Program.cs

using System;
using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace OpenRoIS.Interfaces.Components.Navigation
{
    // ─── Shared type definitions ($defs) ─────────────────────────────


    /// <summary>
    /// Routing policy for Navigation.
    /// 
    /// The XML profile defines routing_policy as a string with values 'time'
    /// or 'distance'. We constrain it to an enum for compile-time safety.
    /// </summary>
    public enum RoutingPolicy
    {
        time,
        distance
    }


    /// <summary>
    /// Result payload for Navigation::Query::get_parameter.
    /// 
    /// Maps to the get_parameter operation in Navigation.xml.
    /// 
    /// Attributes:
    ///     target_positions: Current navigation target positions.
    ///     time_limit: Current time limit setting.
    ///     routing_policy: Current routing policy setting.
    /// </summary>
    public sealed class NavigationGetParameterResult : IEquatable<NavigationGetParameterResult>
    {
        [JsonPropertyName("target_positions")]
        public IReadOnlyList<string> TargetPositions { get; }
        [JsonPropertyName("time_limit")]
        public int TimeLimit { get; }
        [JsonPropertyName("routing_policy")]
        public RoutingPolicy RoutingPolicy { get; }

        public NavigationGetParameterResult(IReadOnlyList<string> targetPositions, int timeLimit, RoutingPolicy routingPolicy)
        {
            TargetPositions = targetPositions;
            TimeLimit = timeLimit;
            RoutingPolicy = routingPolicy;
        }

        public bool Equals(NavigationGetParameterResult? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(TargetPositions, other.TargetPositions) && Equals(TimeLimit, other.TimeLimit) && Equals(RoutingPolicy, other.RoutingPolicy);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NavigationGetParameterResult);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(TargetPositions, TimeLimit, RoutingPolicy);
        }

        public static bool operator ==(NavigationGetParameterResult? left, NavigationGetParameterResult? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NavigationGetParameterResult? left, NavigationGetParameterResult? right)
            => !(left == right);
    }

    /// <summary>
    /// Event payload for Navigation::Event::reached_target.
    /// 
    /// Maps to the reached_target event in Navigation.xml.
    /// 
    /// Attributes:
    ///     target: The reached target destination.
    ///     is_final_target: Whether this is the final destination point.
    /// </summary>
    public sealed class NavigationReachedTargetEvent : IEquatable<NavigationReachedTargetEvent>
    {
        [JsonPropertyName("target")]
        public string Target { get; }
        [JsonPropertyName("is_final_target")]
        public bool IsFinalTarget { get; }

        public NavigationReachedTargetEvent(string target, bool isFinalTarget)
        {
            Target = target;
            IsFinalTarget = isFinalTarget;
        }

        public bool Equals(NavigationReachedTargetEvent? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(Target, other.Target) && Equals(IsFinalTarget, other.IsFinalTarget);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NavigationReachedTargetEvent);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(Target, IsFinalTarget);
        }

        public static bool operator ==(NavigationReachedTargetEvent? left, NavigationReachedTargetEvent? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NavigationReachedTargetEvent? left, NavigationReachedTargetEvent? right)
            => !(left == right);
    }

    /// <summary>
    /// Command payload for Navigation::Command::set_parameter.
    /// 
    /// Maps to the set_parameter operation in Navigation.xml.
    /// 
    /// Attributes:
    ///     target_positions: Navigation target positions as structured data.
    ///         In the XML profile, data_type_ref is 'string[]'.
    ///     time_limit: Intended time limit to complete navigation (default: 0).
    ///     routing_policy: Routing policy: 'time' priority or 'distance' priority
    ///         (default: 'time').
    /// </summary>
    public sealed class NavigationSetParameter : IEquatable<NavigationSetParameter>
    {
        [JsonPropertyName("target_positions")]
        public IReadOnlyList<string> TargetPositions { get; }
        [JsonPropertyName("time_limit")]
        public int TimeLimit { get; }
        [JsonPropertyName("routing_policy")]
        public RoutingPolicy RoutingPolicy { get; }

        public NavigationSetParameter(IReadOnlyList<string> targetPositions, int timeLimit = 0, RoutingPolicy routingPolicy = RoutingPolicy.time)
        {
            TargetPositions = targetPositions;
            TimeLimit = timeLimit;
            RoutingPolicy = routingPolicy;
        }

        public bool Equals(NavigationSetParameter? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(TargetPositions, other.TargetPositions) && Equals(TimeLimit, other.TimeLimit) && Equals(RoutingPolicy, other.RoutingPolicy);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NavigationSetParameter);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(TargetPositions, TimeLimit, RoutingPolicy);
        }

        public static bool operator ==(NavigationSetParameter? left, NavigationSetParameter? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NavigationSetParameter? left, NavigationSetParameter? right)
            => !(left == right);
    }

    /// <summary>
    /// Result of Navigation set_parameter command.
    /// 
    /// Attributes:
    ///     command_id: The assigned command identifier for this navigation command.
    /// </summary>
    public sealed class NavigationSetParameterResult : IEquatable<NavigationSetParameterResult>
    {
        [JsonPropertyName("command_id")]
        public string CommandId { get; }

        public NavigationSetParameterResult(string commandId)
        {
            CommandId = commandId;
        }

        public bool Equals(NavigationSetParameterResult? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(CommandId, other.CommandId);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NavigationSetParameterResult);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(CommandId);
        }

        public static bool operator ==(NavigationSetParameterResult? left, NavigationSetParameterResult? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NavigationSetParameterResult? left, NavigationSetParameterResult? right)
            => !(left == right);
    }

    /// <summary>
    /// Result model for Navigation component_status query.
    /// 
    /// Attributes:
    ///     status: Current status of the Navigation component.
    /// </summary>
    public sealed class NavigationStatusResult : IEquatable<NavigationStatusResult>
    {
        [JsonPropertyName("status")]
        public OpenRoIS.Interfaces.Common.ComponentStatus Status { get; }

        public NavigationStatusResult(OpenRoIS.Interfaces.Common.ComponentStatus status)
        {
            Status = status;
        }

        public bool Equals(NavigationStatusResult? other)
        {
            if (ReferenceEquals(other, this)) return true;
            if (other is null) return false;
            return Equals(Status, other.Status);
        }

        public override bool Equals(object? obj)
        {
            return Equals(obj as NavigationStatusResult);
        }

        public override int GetHashCode()
        {
            return System.HashCode.Combine(Status);
        }

        public static bool operator ==(NavigationStatusResult? left, NavigationStatusResult? right)
            => ReferenceEquals(left, right) || (left is not null && left.Equals(right));
        public static bool operator !=(NavigationStatusResult? left, NavigationStatusResult? right)
            => !(left == right);
    }

}
