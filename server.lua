package.preload['mime'] = function()
end 

package.preload['socket'] = function()
end 

package.preload['copas'] = function()
end 

package.preload['ssl'] = function()
end

local websocket = require('websocket')
local config = {
  port = 8002,
  interface = '*',
  protocols = {
    ['echo'] = function(ws)
      while true do
        local message = ws:receive()
        if message then
          ws:send(message)
        else
          ws:close()
          return
        end
      end
    end,
    ['echo-uppercase'] = function(ws)
      while true do
        local message = ws:receive()
        if message then
          ws:send(message:upper())
        else
          ws:close()
          return
        end
      end
    end,
  };

  default = function(ws)
    ws:send('goodbye strange client')
    ws:close()
  end
}
function websocket.server.copas.listen(config)
end