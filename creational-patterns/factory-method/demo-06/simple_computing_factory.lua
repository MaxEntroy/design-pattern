local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local _M = {}

function _M.GetComputing(computing_type, l, r)
  if computing_type == AddComputing.name then
    return AddComputing.New(l, r)
  elseif computing_type == MinusComputing.name then
    return MinusComputing.New(l, r)
  end
end

return _M
