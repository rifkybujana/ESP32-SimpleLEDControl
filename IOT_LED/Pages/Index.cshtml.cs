using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using IOT_LED.Models;
using IOT_LED.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.Extensions.Logging;

namespace IOT_LED.Pages
{
    public class IndexModel : PageModel
    {
        public IndexModel(
            ILogger<IndexModel> logger,
            JSONFileDataService dataService)
        {
            _logger = logger;
            DataService = dataService;
        }

        private readonly ILogger<IndexModel> _logger;

        public JSONFileDataService DataService;
        public Data Data { get; private set; }

        public void OnGet()
        {
            Data = DataService.GetData();
        }
    }
}
