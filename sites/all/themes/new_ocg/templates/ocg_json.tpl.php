<div id="data-portal-app" ng-controller="datacontroller" ng-cloak>

  <div class="portal-navigation">
    <div id="centers">
      <div class="centers-inner">{{ctd2nodes.nodes.length}} Centers</div>
    </div>

    <div id="center-title">
      <div class="center-title-inner">
        <div ng-repeat="project in ctd2nodes.nodes" class="project">
          <div class="title"><a ng-click="$parent.projectTitle = project.node.title.title; setRow(project.node.row[0].row_number)">{{ project.node.title.title}}</a></div>
          <div class="dataset-count">{{project.node.row.length}} Datasets</div>
        </div>
      </div>
    </div>

    <div id="project-title">
      <div class="project-title-inner">
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row">
            <a ng-click="setRow(row.row_number)">{{row.project_title.title}}</a>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div id="row-info">
    <div class="row-info-approaches">
      <div id="experimental-approaches">

        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <h2>{{row.dpp.title}}</h2>
            <div class="appraoches-description">
            <div ng-bind-html="row.dpp.body | crop: 200"></div><a href="{{row.project_title.url}}"> {{row.dpp.body.length > 200 ? 'Read More...' : ''}}</a>
            </div>
            <h3 class="approaches-header">Experimental Approaches</h3>
            <div ng-repeat="approach in row.dpp" class="approaches-listing">
              <div class="approaches-listing-title">{{approach.dpp_title}}</div>
              <div ng-bind-html="approach.dpp_body | crop: 150"></div><a href="{{row.project_title.url}}"> {{approach.dpp_body.length > 150 ? 'Read More...' : ''}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="row-info-remaining">
      <div id="data">
        <h3 class="data-header">Data</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow">
            <div ng-repeat="data in row.data">
              Access the <a href="/{{data.data_link.url}}">{{data.data_link.title}}</a>
            </div>
          </div>
        </div>
      </div>

      <div id="investigator">
        <h3 class="investigator-header">Principal Investigator</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow">
            <div ng-repeat="investigator in row.investigator">
              <div>{{investigator.investigator}}</div>
            </div>
          </div>
        </div>
      </div>

      <div id="contact">
        <h3 class="contact-header">Contact Name</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow">
            <div ng-repeat="contact in row.contact">
              <div ng-repeat="contact_link in contact.contact_link">
                <a href="/{{contact_link.url}}">{{contact_link.title}}</a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div id="submission-date">
        <h3 class="submission-date-header">Submission Date</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow | limitTo:1">
            <div>{{row.submission_date * 1000| date : "y-MM-dd"}}</div>
          </div>
        </div>
      </div>

      <div id="reference">
        <h3 class="reference-header">Reference</h3>
        <div ng-repeat="project in ctd2nodes.nodes| filter:projectTitle | limitTo:1">
          <div ng-repeat="row in project.node.row| sameRowNumber:filterRow">
            <div ng-repeat="paper in row.paper">
              <a href="/{{paper.paper_link.url}}">{{paper.paper_link.title}}</a>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</div>