var app = angular.module('app', ['ngSanitize']).controller('datacontroller', function ($scope, $http) {
  $http.get('/programs/ctd2/data-portal-json').success(function (result) {
    $scope.ctd2nodes = result;
    const assayList = [];
    angular.forEach($scope.ctd2nodes.nodes, function (nodes, key) {
      angular.forEach(nodes.node.row, function (row, key) {
        angular.forEach(row.assay_type, function (assay_type, key) {
          assayList.push({assay: assay_type.name});
        });
      });
    });

    assays = assayList.reduce(function (tally, method) {
      tally[method.assay] = (tally[method.assay] || 0) + 1;
      return tally;
    }, {});

    var assaysObj = [];
    angular.forEach(assays, function (number, key) {
      assaysObj.push({assay: key, number: number, node: {}});
    });

    assaysObj = assaysObj.sort((a, b) => a.assay.localeCompare(b.assay));

    angular.forEach(assaysObj, function (assays, assayObjKey) {
      var count = 0;
      angular.forEach($scope.ctd2nodes.nodes, function (nodes, nodesKey) {
        angular.forEach(nodes.node.row, function (row, rowKey) {
          angular.forEach(row.assay_type, function (assay_type, assayKey) {
            if (assays.assay == assay_type.name) {
              var dppCount = 0;
              var dataCount = 0;
              var investigatorCount = 0;
              var contactCount = 0;
              var paperCount = 0;
              assaysObj[assayObjKey].node[count] = {
                id: nodes.node.id,
                row_number: row.row_number,
                project_title: row.project_title.title,
                project_title_url: row.project_title.url,
                dpp_title: row.dpp.title,
                dpp_body: row.dpp.body,
                dpp: {},
                data: {},
                investigator: {},
                contact: {},
                submission_date: row.submission_date,
                paper: {}
              };
              if (typeof row.dpp[0] !== 'undefined') {
                angular.forEach(row.dpp, function (dppRow, dppKey) {
                  assaysObj[assayObjKey].node[count].dpp[dppCount] = {dpp_title: dppRow.dpp_title, dpp_body: dppRow.dpp_body};
                  dppCount++
                });
              }
              ;
              if (typeof row.data[0] !== 'undefined') {
                angular.forEach(row.data, function (dataRow, dataKey) {
                  if (dataRow.data_link !== null) {
                    assaysObj[assayObjKey].node[count].data[dataCount] = {data_title: dataRow.data_link.title, data_url: dataRow.data_link.url};
                    dataCount++;
                  }
                  ;
                });
              }
              ;
              if (typeof row.investigator !== 'undefined') {
                if (typeof row.investigator[0] !== 'undefined') {
                  angular.forEach(row.investigator, function (investigatorRow, investigatorKey) {
                    if (investigatorRow.investigator !== null) {
                      assaysObj[assayObjKey].node[count].investigator[investigatorCount] = {investigator: investigatorRow.investigator};
                      investigatorCount++;
                    }
                    ;
                  });
                }
                ;
              }
              ;
              if (typeof row.contact !== 'undefined') {
                if (typeof row.contact[0] !== 'undefined') {
                  angular.forEach(row.contact, function (contactRow, contactKey) {
                    assaysObj[assayObjKey].node[count].contact[contactCount] = contactRow;
                    //angular.forEach(contactRow, function (contactLinkRow, contactLinkKey) {
                      //if (contactLinkRow.title !== null) {
                        //assaysObj[assayObjKey].node[count].contact[contactCount] = {contact_title: contactLinkRow.title, contact_url: contactLinkRow.url};
                        //contactCount++;
                      //};
                      //console.log(contactLinkRow);
                    //});
                  });
                }
                ;
              }
              ;
              if (typeof row.paper !== 'undefined') {
                if (typeof row.paper[0] !== 'undefined') {
                  angular.forEach(row.paper, function (paperRow, paperKey) {
                    if (paperRow.paper_link !== null) {
                      assaysObj[assayObjKey].node[count].paper[paperCount] = {paper_title: paperRow.paper_link.title, paper_url: paperRow.paper_link.url};
                      paperCount++;
                    }
                    ;
                  });
                }
                ;
              }
              ;
              count++;
            }
            ;
          });
        });
      });
    })
    $scope.methods = assaysObj;
    console.log(assaysObj);
  });

  $scope.clickChoice = 'centers';
  $scope.revealData = function (value) {
    if (value == 'centers')
      return true;
    else
      return false;
  }
  $scope.filterRow = '';
  $scope.filterId = '';
  $scope.setRow = function (row) {
    $scope.filterRow = row;
  };

  $scope.setMethod = function (id, row) {
    $scope.filterId = id;
    $scope.filterRow = row;
  }
  
  $scope.filterMethodRow = function(items) {
    var result = {};
    if ($scope.filterRow && $scope.filterId) {
      angular.forEach(items, function(value, key) {
        if (value.id  === $scope.filterId && value.row_number === $scope.filterRow) {
          result[key] = value;
        };
      });
    } else {
      result = items;
    };
    return result;
  };
}).filter('sameRowNumber', function () {
  return function (values, rowNumber) {
    if (!rowNumber) {
      // initially don't filter
      return values;
    }
    // filter when we have a selected groupId
    return values.filter(function (value) {
      return value.row_number === rowNumber;
    })
  }
}).filter('crop', function () {
  return function (input, limit, respectWordBoundaries, suffix) {
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

jQuery(document).ready(function () {
  angular.bootstrap(document.getElementById('data-portal-app'), ['app']);
});