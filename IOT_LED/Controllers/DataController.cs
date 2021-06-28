using IOT_LED.Models;
using IOT_LED.Services;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace IOT_LED.Controllers
{
    [Route("[controller]")]
    [ApiController]
    public class DataController : ControllerBase
    {
        public DataController(JSONFileDataService dataService)
        {
            DataService = dataService;
        }

        public JSONFileDataService DataService { get; }

        [HttpGet]
        public Data Get()
        {
            return DataService.GetData();
        }
    }
}
