# slogger.inc
Simple include log for sa-mp server. The result will be saved on */scriptfiles/logs/* folder. 

## Features
* Recorded logs
* Remove Logs
  
## Example
---------------------------------
```php

CMD:givemoney(playerid, params[])
{
		new string[128], giveplayerid, money;
		if(sscanf(params, "ud", giveplayerid, money)) return SendClientMessage(playerid, -1, " /givemoney [playerid] [money]");

		if(IsPlayerConnected(giveplayerid))
		{
			GivePlayerCash(giveplayerid, money);
			format(string, sizeof(string), "%s has given %s $%d", GetPlayerName(playerid), GetPlayerName(giveplayerid),money);
			Log_Write("logs/admin.log", string);
		}
    return 1;
}
```
