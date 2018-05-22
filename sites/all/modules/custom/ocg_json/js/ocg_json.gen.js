var app = angular.module('app', ['ngSanitize']).controller('datacontroller', function($scope, $http){
  $http.get('/programs/ctd2/data-portal-json').success(function(result){
    $scope.ctd2nodes = result;
  });
  $scope.filterKey = function(filter) {
    //console.log(row);
    if(row.row_number == filter.row_number)
    {
      console.log(row.row_number);  
      return true; // this will be listed in the results
    }
    return false; // otherwise it won't be within the results
  };
  $scope.filterRow = '';
  $scope.setRow = function(row) {
    console.log(row);
    $scope.filterRow = row;
  }
  
}).filter('sameRowNumber', function(){
  return function(values, rowNumber) {
    if(!rowNumber) {
      // initially don't filter
      return values;
    }
    // filter when we have a selected groupId
    return values.filter(function(value){
      return value.row_number === rowNumber;
    })
  }
}).filter('crop', function(){
	return function(input, limit, respectWordBoundaries, suffix){
		if (input === null || input === undefined || limit === null || limit === undefined || limit === '') {
			return input;
		}
		if (angular.isUndefined(respectWordBoundaries)) {
			respectWordBoundaries = true;
		}
		if (angular.isUndefined(suffix)) {
			suffix = ' ';
		}

		if (input.length <= limit) {
			return input;
		}

		limit = limit - suffix.length;

		var trimmedString = input.substr(0, limit);
		if (respectWordBoundaries) {
			return trimmedString.substr(0, Math.min(trimmedString.length, trimmedString.lastIndexOf(" "))) + suffix;
		}
		return trimmedString + suffix;
}
});

jQuery(document).ready(function() {
  angular.bootstrap(document.getElementById('data-portal-app'), ['app']);
});