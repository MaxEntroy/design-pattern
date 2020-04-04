local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local _M = {}

function _M.New(ct)
  local o = {
    computing_type = ct
  }
  setmetatable(o, {__index = _M})

  return o
end

function _M.GetComputing(self, l, r)
  if self.computing_type == AddComputing.name then
    return AddComputing.New(l, r)
  elseif self.computing_type == MinusComputing.name then
    return MinusComputing.New(l, r)
  end
end

return _M
