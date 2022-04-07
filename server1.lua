package.preload['websocket']

local = websocket.new_from_uri("wss://echo.websocket.org")
assert(ws:send("koo-eee!"))
local data = assert(ws:receive())
assert(data == "koo-eee!")
assert(ws:close())