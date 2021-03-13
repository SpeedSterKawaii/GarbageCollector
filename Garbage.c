static int GarbageCollector(DWORD rL)  {
	void* UD = lua_touserdata(L, 1);
	lua_pushvalue(L, 1);
	lua_gettable(L, LUA_REGISTRYINDEX);
	if (!lua_isnil(L, -1)) {
		int Reference = lua_tointeger(L, -1);
		r_lua_settop(RL, 0);
		return 1;
	}
	lua_pop(L, 1);
	return 0;
}

// Register the Garbage Collector

r_luaL_register(RL, "garbagecollector", GarbageCollector);
