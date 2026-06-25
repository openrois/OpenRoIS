import { describe, it, expect } from "vitest";
import {
  BusAdapterError,
  ComponentNotFoundError,
  type BusAdapter,
  type DiscoverRequest,
  type DiscoverResponse,
  type CommandRequest,
  type InvokeResponse,
  type QueryRequest,
  type QueryResponse,
  type SubscribeId,
  type SubscribeRequest,
  type SubscribeResponse,
  type EventSink,
} from "../src/bus";
import type { ReturnCode } from "../src/hri";

describe("BusAdapterError", () => {
  it("creates with default return code", () => {
    const err = new BusAdapterError("something went wrong");
    expect(err.message).toBe("something went wrong");
    expect(err.returnCode).toBe("ERROR");
    expect(err.name).toBe("BusAdapterError");
    expect(err instanceof Error).toBe(true);
  });

  it("creates with custom return code", () => {
    const err = new BusAdapterError("bad param", "BAD_PARAMETER");
    expect(err.returnCode).toBe("BAD_PARAMETER");
  });
});

describe("ComponentNotFoundError", () => {
  it("creates with component ref and UNSUPPORTED code", () => {
    const err = new ComponentNotFoundError("robot/missing");
    expect(err.message).toBe("Component not found: robot/missing");
    expect(err.returnCode).toBe("UNSUPPORTED");
    expect(err.componentRef).toBe("robot/missing");
    expect(err instanceof BusAdapterError).toBe(true);
  });
});

describe("BusAdapter interface", () => {
  it("can be implemented by a dummy class", () => {
    class DummyAdapter implements BusAdapter {
      async discover(_request: DiscoverRequest): Promise<DiscoverResponse> {
        return { return_code: "OK", component_ref_list: [] };
      }
      async invoke(_request: CommandRequest): Promise<InvokeResponse> {
        return { return_code: "OK", command_id: "", results: [] };
      }
      async query(_request: QueryRequest): Promise<QueryResponse> {
        return { return_code: "OK", results: [] };
      }
      async subscribe(_request: SubscribeRequest, _sink: EventSink): Promise<SubscribeResponse> {
        return { return_code: "OK", subscribe_id: "sub-1" };
      }
      async unsubscribe(_subscribeId: SubscribeId): Promise<ReturnCode> {
        return "OK";
      }
    }

    const adapter = new DummyAdapter();
    expect(adapter).toBeDefined();
  });

  it("EventSink is an async callback type", () => {
    const sink: EventSink = async (_envelope) => {
      // no-op
    };
    expect(typeof sink).toBe("function");
  });
});